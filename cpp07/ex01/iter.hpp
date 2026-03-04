#ifndef ITER
#define ITER
#include <iostream>
template<typename T, typename Func>
void iter(T* arr, const size_t size, Func function)
{
    for (size_t i = 0; i < size; i++)
    {
        function(arr[i]);
    }
}

#endif