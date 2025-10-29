#ifndef MateriaSource_hpp
#define MateriaSource_hpp

#include "IMateriaSource.hpp"
#include "AMateria.hpp"


class MateriaSource :public IMateriaSource
{
private:
    AMateria *materiasource[4];
public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource& operator=( MateriaSource const &other);
    MateriaSource(MateriaSource const &other);
    void learnMateria(AMateria*);
    AMateria *createMateria(std::string const &);
};


#endif