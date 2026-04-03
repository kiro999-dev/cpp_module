#include "PmergeMe.hpp"
int error()
{
    std::cerr << "Error" << std::endl;
    return -1;
}
bool isvalid(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == ' ')
        {
            i++;
            continue;
        }
        if (str[i] == '+' && !isdigit(str[i + 1]))
            return false;
        if (!isdigit(str[i]) && str[i] != '+')
            return false;
        i++;
    }
    return true;
}
void VectorResult(std::vector<int> &numbersV)
{
    struct timeval start, end;
    std::size_t size = numbersV.size();

    std::cout << "Before: ";
    PrintContainer(numbersV);
    gettimeofday(&start, NULL);
    numbersV = Ford_jhonson(numbersV);
    gettimeofday(&end, NULL);
    std::cout << "After:  ";
    PrintContainer(numbersV);
    double ms = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
    std::cout << "Time to process a range of " << size
              << " elements with std::vector : " << ms << " ms\n";
}
void DequeResult(std::deque<int> &numbersD)
{
    struct timeval start, end;
    std::size_t size = numbersD.size();
    gettimeofday(&start, NULL);
    numbersD = Ford_jhonson_D(numbersD);
    gettimeofday(&end, NULL);
    double ms = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
    std::cout << "Time to process a range of " << size
              << " elements with std::deque :  " << ms << " ms\n";
}
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error\n";
        return -1;
    }
    std::vector<int> numbersV;
    std::deque<int> numbersD;
    int i = 1;
    while (argv[i])
    {
        if (isvalid(argv[i]) == false)
            return error();
        if (!FillContainer(numbersV, argv[i]))
            return error();
        if (!FillContainer(numbersD, argv[i]))
            return error();
        i++;
    }
    VectorResult(numbersV);
    DequeResult(numbersD);
}