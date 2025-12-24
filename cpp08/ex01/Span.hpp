#ifndef SPAN
#define SPAN
#include <vector>
#include <iostream>
#include <stdexcept> 
#include <limits>

class Span
{
private:
    std::vector<int> span;
    unsigned int size;
    unsigned elm_count;
public:
    Span();
    Span(unsigned int N);
    Span(const Span &obj);
    const Span& operator=(const Span &obj);
    void addNumber(int number);
    void addNumbers(std::vector<int> numbers);
    int shortestSpan();
    int longestSpan();
    ~Span();
};


#endif