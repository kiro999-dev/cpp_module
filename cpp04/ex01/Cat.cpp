#include "Cat.hpp"
Cat::Cat():Animal("Cat")
{
    this->brain = new Brain();
    this->type = "Cat";
    std::cout<<"Cat Constructor has been called "<<std::endl;
}

Cat::~Cat()
{
    delete this->brain;
     std::cout<<"Cat Destructor has been called "<<std::endl;
}
Cat::Cat(Cat const& other):Animal(other)
{
    delete brain;
    brain = new Brain(*other.brain);
    std::cout<<"Cat copy Constructor has been called "<<std::endl;
}
Cat& Cat::operator=(Cat const& other)
{
    if (this == &other)
        return *this;
    Animal::operator=(other);
    delete brain;
    brain = new Brain(*other.brain);
    std::cout<<"Cat copy assignment  Constructor has been called "<<std::endl;
    return *this;
}
void Cat::makeSound() const
{
    std::cout<<"meow meow meeeeow"<<std::endl;
}