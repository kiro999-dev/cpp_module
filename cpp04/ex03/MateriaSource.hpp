#ifndef MateriaSource_hpp
#define MateriaSource_hpp
#include " IMateriaSource.hpp"
class MateriaSource :public MateriaSource
{
private:
    AMateria *materiasource[4];
public:
    MateriaSource();
    ~MateriaSource();
    void learnMateria(AMateria*);
    AMateria *createMateria(std::string const &);
};

MateriaSource::MateriaSource(/* args */)
{
}

MateriaSource::~MateriaSource()
{
}

#endif