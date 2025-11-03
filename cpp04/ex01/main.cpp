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
    std::cout<<"------------------------------------"<<std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        delete array[i];
    }
    std::cout << "\n========== Test 8: Mixed Array with Deletion ==========" << std::endl;
    {
        Animal *mixed[6];
        mixed[0] = new Dog();
        mixed[1] = new Cat();
        mixed[2] = new Dog();
        mixed[3] = new Cat();
        mixed[4] = new Dog();
        mixed[5] = new Cat();
        
        std::cout << "\nAll animals making sounds:" << std::endl;
        for (int i = 0; i < 6; i++)
        {
            std::cout << i << ". ";
            mixed[i]->makeSound();
        }
        
        std::cout << "\nDeleting all..." << std::endl;
        for (int i = 0; i < 6; i++)
        {
            delete mixed[i];
        }
    }
  
    return 0;
}