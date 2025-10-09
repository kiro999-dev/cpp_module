#include "Point.hpp"

int main()
{

    Point a(0, 0);
    Point c(0, 20);
    Point b(10, 30);
    Point p(10, 30);

    if (bsp(a, b, c, p))
        std::cout << "its inside "<<std::endl;
    else
        std::cout << "its outside "<<std::endl;

    return 0;
}