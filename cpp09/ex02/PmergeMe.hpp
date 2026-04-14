#ifndef PmergeMe_hpp
#define PmergeMe_hpp
#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <stdlib.h>
#include <deque>
#include <algorithm>
#include <sys/time.h>
#include <cerrno>

bool isSorted(const std::vector<int> &arr);
int parse_int(const char *str, int *result);
std::vector<std::string> splitString(const std::string &str, char delimiter);
std::deque<int> Ford_jhonson_D(std::deque<int> &numbersD);
std::vector<int> Ford_jhonson(std::vector<int> &numbersV);

template <typename C>
void PrintContainer(C numbers)
{
    for (size_t i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";
}
template <typename C>
C jacobSthal(int n)
{
    typedef typename C::value_type T;

    C jacob;
    C Sq;
    T x = 3;
    T xprim;

    jacob.push_back(0);
    jacob.push_back(1);
    int i = 2;
    while (x <= n)
    {
        x = jacob[i - 1] + 2 * jacob[i - 2];
        jacob.push_back(x);
        i++;
    }
    i = 2;
    int size = 0;
    while (size < n)
    {
        if (jacob[i] <= n)
            Sq.push_back(jacob[i]);
        size++;
        if (jacob.size() > (size_t)i)
        {
            x = jacob[i];
            xprim = jacob[i - 1] + 1;
            while (x > xprim)
            {
                size++;
                x--;
                if (x <= n)
                    Sq.push_back(x);
            }
        }
        i++;
    }
    return Sq;
}
template <typename T>
bool FillContainer(T &numbersV, char *str)
{
    size_t i = 0;
    int res = 0;
    std::vector<std::string> numbersS = splitString(str, ' ');

    while (i < numbersS.size())
    {
        if (!parse_int(numbersS[i].c_str(), &res))
            return false;
        numbersV.push_back(res);
        i++;
    }
    return true;
}

#endif