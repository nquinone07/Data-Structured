#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

template<typename TYPE, size_t SIZE> 
class Stack
{
public:

    /// SPECIAL MEMBER FUNCTIONS ///
    // Default constructor
    Stack();
    // Default destructor
    ~Stack();
    // Copy Assignment Operator/Ctor
    Stack(const Stack &) = default;
    void operator=(const Stack &) = default;
    // Move Operator/Ctor
    Stack(const Stack &&) = default;
    void operator=(const Stack &&) = default;

    /// FUNCTIONS ///
    // Peek the top of the stack, returning the element that was
    // most recently added. This operation is not destructive, 
    // the element peeked is NOT removed
    TYPE& peek();

    // Destructive, return and remove the top of the stack
    TYPE pop();

    // Add an element onto the stack 
    bool push(TYPE);

    // Check if the stack is full
    inline bool isFull();

    // Check if the stack is empty
    inline bool isEmpty();

private:

    // Statically allocated array, underlying data structure
    TYPE stack[SIZE];
    // Bookeeping
    size_t length;
};
   
template<typename TYPE, size_t SIZE>
inline bool Stack::isEmpty()
{
    return 0 == length;
}

template<typename TYPE, size_t SIZE>
inline bool Stack::isFULL()
{
    return SIZE == length;
}
#endif 
