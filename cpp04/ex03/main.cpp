#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
   IMateriaSource *mater = new MateriaSource();
   ICharacter *zakaria = new Character("zakaria");
    ICharacter *zglo = new Character("zglooo");
   mater->learnMateria(new Ice());
   mater->learnMateria(new Cure());

   AMateria *skill  = mater->createMateria("ice");
    zakaria->equip(skill);
    zakaria->use(0,*zglo);
    delete mater;
    delete zakaria;
    delete zglo;
    return 0;
}