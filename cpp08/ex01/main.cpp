#include "Span.hpp"
int main()
{
    try
    {
        Span sp = Span(5);
        std::vector<int>x= {-1,-2,4,4};
        sp.addNumbers(x);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   
    return 0;
}