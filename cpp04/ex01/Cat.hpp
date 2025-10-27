#ifndef Cat_HPP
#define Cat_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Cat:public Animal
{
    private:
        Brain *brain;
public:
    Cat();
    ~Cat();
    Cat(Cat const& other);
    Cat &operator=(Cat const& other);
    void makeSound() const;
};

#endif