#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP
#include <iostream>

class WrongAnimal
{
protected:
    std::string type;
    
public:
    WrongAnimal();
    WrongAnimal(std::string type);
    virtual ~WrongAnimal(); 
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal& operator=(const WrongAnimal &other);
    std::string const& getType() const;
    void makeSound() const;
};

#endif