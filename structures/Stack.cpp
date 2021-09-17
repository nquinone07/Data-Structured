#include <Stack.h>

template<typename TYPE, size_t SIZE>
Stack<TYPE, SIZE>::Stack() : 
    stack { },
    length(0)
{
}
    
template<typename TYPE, size_t SIZE>
bool Stack<TYPE, SIZE>::push(TYPE pushed)
{
    bool retval = true;
    // If not full add to the stack 
    if (!full())
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
TYPE Stack<TYPE, SIZE>::pop()
{
    TYPE popped;
    // If not full add to the stack 
    if (!empty())
    {
       popped = stack[length--];
    }
    return popped;
}

template<typename TYPE, size_t SIZE>
TYPE Stack<TYPE, SIZE>::peek()
{
    TYPE peeked;
    // If not full add to the stack 
    if (!empty())
    {
       peeked = stack[length];
    }
    return peeked;
}
