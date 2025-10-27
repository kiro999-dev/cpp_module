#include "Dog.hpp"
Dog::Dog():Animal("Dog")
{
    this->brain = new Brain();
    this->type = "Dog";
    std::cout<<"Dog Constructor has been called "<<std::endl;
}

Dog::~Dog()
{
    delete this->brain;
     std::cout<<"Dog Destructor has been called "<<std::endl;
}
Dog::Dog(Dog const& other):Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout<<"Dog copy Constructor has been called "<<std::endl;
}
Dog& Dog::operator=(Dog const& other)
{
    
    Animal::operator=(other);
    delete brain;
    brain = new Brain(*other.brain);
    std::cout<<"Dog copy assignment  Constructor has been called "<<std::endl;
    return *this;
}
void Dog::makeSound() const
{
    std::cout<<"3aww 3aw 3awwww"<<std::endl;
}