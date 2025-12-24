#include "Span.hpp"
int Span::shortestSpan()
{
    if(size <=1)
        throw std::runtime_error("no span can be found");
    std::vector<int>::iterator it = span.begin();
    int min = std::numeric_limits<int>::max();
    while ((it+1) != span.end())
    {
        if(min >std::abs(*(it+1) - *it))
            min = std::abs(*(it+1) - *it);
        it++;
    }
    return min;
}
int Span::longestSpan()
{
    if(size <=1)
        throw std::runtime_error("no span can be found");
    std::vector<int>::iterator it = span.begin();
    int max = std::numeric_limits<int>::min();
    while ((it+1) != span.end())
    {
        if(max < std::abs(*(it+1) - *it))
            max = std::abs(*(it+1) - *it);
        it++;
    }
    return max;
}
void Span::addNumbers(std::vector<int> numbers)
{
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
       addNumber(*it);
    }
    
}
void Span::addNumber(int number)
{
    if(elm_count < size)
    {
        span.push_back(number);
        elm_count++;
    }
    else
        throw std::runtime_error("span if full");
}
Span::Span(const Span &obj)
{
    size = obj.size;
    span = obj.span;
}
const Span &Span::operator=(const Span &obj)
{
    if(this == &obj)
        return *this;
    size = obj.size;
    span = obj.span;
    return *this;
}
Span::Span(unsigned int N)
{
    size = N;
    elm_count = 0;
}
Span::Span():size(0),elm_count(0)
{
}

Span::~Span()
{
}