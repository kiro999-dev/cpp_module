#ifndef Cat_HPP
#define Cat_HPP
#include "Animal.hpp"
class Cat:public Animal
{

public:
    Cat();
    ~Cat();
    Cat(Cat& other);
    Cat operator=(Cat& other);
    void makeSound();
};

#endif