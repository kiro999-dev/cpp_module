#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
    {
        materiasource[i] = NULL;
    }
    std::cout <<"MateriaSource Constructor has been called " << std::endl;
}
MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
    {
        if (materiasource[i] != NULL)
            delete materiasource[i];
    }
    std::cout << " MateriaSource destructor has been called " << std::endl;
}
void MateriaSource::learnMateria(AMateria *am)
{
    if (!am)
        return;
    for (size_t i = 0; i < 4; i++)
    {
        if (materiasource[i] == NULL)
        {
            materiasource[i] = am;
            return;
        }
    }
    delete am;
}
AMateria *MateriaSource::createMateria(std::string const &string)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (materiasource[i] && materiasource[i]->getType() == string)
        {
            return materiasource[i]->clone();
        }
    }
    return NULL;
}
MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
    if (this == &other)
        return *this;
    for (size_t i = 0; i < 4; i++)
    {
        if (materiasource[i])
            delete materiasource[i];
        if (other.materiasource[i])
            materiasource[i] = other.materiasource[i]->clone();
        else
            materiasource[i] = NULL;
    }
    std::cout << " MateriaSource copy assignment  Constructor has been called " << std::endl;
    return *this;
}
MateriaSource::MateriaSource(MateriaSource const &other)
{

    for (size_t i = 0; i < 4; i++)
    {
        if (other.materiasource[i])
            materiasource[i] = other.materiasource[i]->clone();
        else
            materiasource[i] = NULL;
    }
    std::cout << " MateriaSource copy Constructor has been called " << std::endl;
}