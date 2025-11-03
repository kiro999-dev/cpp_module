#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "========== Test 1: Subject Test (Basic Functionality) ==========" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        ICharacter* me = new Character("me");
        
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        
        ICharacter* bob = new Character("bob");
        
        me->use(0, *bob);
        me->use(1, *bob);
        
        delete bob;
        delete me;
        delete src;
    }

    std::cout << "\n========== Test 2: Duplicate Equip Protection ==========" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        
        Character* player = new Character("player");
        
        AMateria* ice = src->createMateria("ice");
        std::cout << "\n--- Equipping same materia twice ---" << std::endl;
        player->equip(ice);
        player->equip(ice);  
        
        std::cout << "\n--- Unequipping and re-equipping ---" << std::endl;
        player->unequip(0);
        player->equip(ice);  
        
        delete player;
        delete src;
    }

    return 0;
}