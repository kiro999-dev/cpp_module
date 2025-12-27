#ifndef ESAYFIND
#define ESAYFIND
#include <iostream>
#include <algorithm>
template <typename T>
const std::string easyfind(T &container, int val)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), val);
    if (it != container.end())
        return std::string("value is found");
    else
        return std::string("value is not found");
}
#endif