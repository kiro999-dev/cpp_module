#include "Brain.hpp"
Brain::Brain()
{
    for (size_t i = 0; i < 100; i++)
    {
        ideas[i] = "";
    }
    
     std::cout<<"Brain Constructor has been called "<<std::endl;
}

Brain::~Brain()
{
     std::cout<<"Brain Destructor has been called "<<std::endl;
}
Brain::Brain(Brain const& other)
{
    for (size_t i = 0; i < 100; i++)
    {
       this->ideas[i] = other.ideas[i];
    }
    
    std::cout<<"Brain copy Constructor has been called "<<std::endl;
}
Brain& Brain::operator=(Brain const& other)
{
    if(&other == this)
        return *this;
    for (size_t i = 0; i < 100; i++)
    {
       this->ideas[i] = other.ideas[i];
    }
    std::cout<<"Brain copy assignment  Constructor has been called "<<std::endl;
    return *this;
}