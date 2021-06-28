#include <Stack.h>

template<typename TYPE, size_t SIZE>
Stack::Stack()
: stack { },
  length(0)
  top(0)
{
}
    
template<typename TYPE, size_t SIZE>
bool Stack::push(TYPE pushed)
{
    bool retval = true;
    // If not full add to the stack 
    if (!isFull)
    {
       stack[length++] = pushed; 
    }
    // Otherwise the stack is full, failed to add
    else
    {
        retval = false;
    }
    return retval;
}

template<typename TYPE, size_t SIZE>
TYPE Stack::pop()
{
    TYPE popped;
    // If not full add to the stack 
    if (!isEmpty())
    {
       popped = stack[length--];
    }
    return popped;
}

template<typename TYPE, size_t SIZE>
const TYPE& Stack::peek()
{
    const TYPE& peeked;
    // If not full add to the stack 
    if (!isEmpty())
    {
       peeked = stack[length];
    }
    return popped;
}
