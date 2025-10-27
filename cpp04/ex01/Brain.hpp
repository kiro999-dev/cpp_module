#ifndef Brain_HPP
#define Brain_HPP
#include <iostream>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    ~Brain();
    Brain(Brain const &other);
    Brain &operator=(Brain const &other);
};

#endif