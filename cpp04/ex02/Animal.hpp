#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
protected:
    std::string type;
    
public:
    Animal();
    Animal(std::string type);
    virtual ~Animal(); 
    Animal(const Animal &other);
    Animal& operator=(const Animal &other);
    std::string const& getType() const;
    virtual void makeSound() const = 0;
};

#endif