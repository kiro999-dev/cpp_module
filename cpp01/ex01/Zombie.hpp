#include <iostream>

class Zombie
{
private:
   std::string name;
public:
    void announce( void );
    Zombie();
    Zombie(std::string name);
    void SetName(std::string name);
    ~Zombie();
};
Zombie* zombieHorde( int N, std::string name );