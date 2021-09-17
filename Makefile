## Compilation Flags ##
FLAGS     := -Werror -Wall -Wextra -fpic -std=c++11
LINK_OPTS := -shared -o

## Output Directories ## 
BUILD := build
LIB   := lib

## Ranlib ##
RANLIB := ranlib

## Source Directories ##
DIRS := $(subst ./,,$(shell find . -maxdepth 1 -type d -not -path ./$(BUILD) \
													   -not -path ./$(LIB) \
													   -not -path '*/\.*' \
													   -not -path '.'))

## Includes ##
INCLUDE := $(addprefix -I,$(DIRS))

## Source Files ## 
SRCS := $(subst ./,,$(shell find $(DIRS) -name \*.cpp))

## Objects ##
OBJS := $(SRCS:%.cpp=$(BUILD)/%.o)

## Libraries ##
LIBS := $(addsuffix .a,$(addprefix $(LIB)/lib-,$(DIRS)))
LIBS += $(addsuffix .so,$(addprefix $(LIB)/lib-,$(DIRS)))

.SUFFIXES: .cpp .o .a .so
.PHONY: lib clean setup printenv

## Rules ##
printenv:
		@echo
		@echo "DIRS         : $(DIRS)"
		@echo "SOURCE FILES : $(SRCS)"
		@echo "OBJECT FILES : $(OBJS)"
		@echo "LINKER OPTS  : $(LINK_OPTS)"
		@echo "FLAGS        : $(FLAGS)"
		@echo
setup:	
		@echo 
		@echo "Creating output directories..."
		@mkdir -p $(LIB)
	    @for dir in $(DIRS); do mkdir -p $(BUILD)/$$dir; done

clean:	
		@echo 
		@echo "Cleaning output directories..."
		@rm -rf $(BUILD) $(LIB)

lib: setup $(LIBS)
		@echo 
		@echo "Built data structures dynamic & static $^!"

.SECONDEXPANSION:
$(LIB)/lib-%.a: $(OBJS)
		@echo
		@echo "Building static library [ $@ ]..."
		$(AR) rc $@ $^
		$(RANLIB) $@

$(LIB)/lib-%.so: $(OBJS)
		@echo
		@echo "Building shared library [ $@ ]..."
		$(CXX) $(LINK_OPTS) $@ $^
	
$(OBJS): $(SRCS) 
		@echo
		@echo "Compiling object file [ $@ ]..."
		$(CXX) $(FLAGS) $(INCLUDE) -o $@ -c $(addsuffix .cpp,$(subst $(BUILD)/,,$*))
