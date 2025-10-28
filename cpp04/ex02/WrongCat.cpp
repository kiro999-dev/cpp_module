#include "WrongCat.hpp"
WrongCat::WrongCat():WrongAnimal("WrongCat")
{
    this->type = "WrongCat";
     std::cout<<"WrongCat Constructor has been called "<<std::endl;
}

WrongCat::~WrongCat()
{
     std::cout<<"WrongCat Destructor has been called "<<std::endl;
}
WrongCat::WrongCat(WrongCat const& other) :WrongAnimal(other)
{
    this->type = other.type;
    std::cout<<"WrongCat copy Constructor has been called "<<std::endl;
}
WrongCat& WrongCat::operator=(WrongCat const& other)
{
    WrongAnimal::operator=(other);
    this->type = other.type;
    std::cout<<"WrongCat copy assignment  Constructor has been called "<<std::endl;
    return *this;
}
void WrongCat::makeSound() const
{
    std::cout<<"meow meow meeeeow maowow"<<std::endl;
}