#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
int main()
{
    const Animal *array[10];

    for (size_t i = 0; i < 10; i++)
    {
        if(i < 5)
        {
            array[i] = new Dog();
        }
        else
            array[i] = new Cat();
    }
    
    for (size_t i = 0; i < 10; i++)
    {
        delete array[i];
    }
 
    
    std::cout<<"------------------------------------"<<std::endl;
  
    return 0;
}