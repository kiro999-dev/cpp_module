#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout<<"------------------------------------"<<std::endl;
    const WrongAnimal *a = new WrongAnimal();
    const WrongAnimal *b = new WrongCat();
    std::cout<<a->getType()<<" "<<std::endl;
    std::cout<<b->getType()<<" "<<std::endl;
    a->makeSound();
    b->makeSound();

   
    return 0;
}