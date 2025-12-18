#include "Intern.hpp"

Intern::Intern()
{
}
Intern::Intern(Intern &o)
{
    (void)o;
}
Intern Intern::operator=(Intern &o)
{
    (void)o;
    return *this;
}
Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string Forms[3]={"shrubbery creation","robotomy request","presidential pardon"};
    int indx = -1;
    for (size_t i = 0; i < 3; i++)
    {
        if (formName == Forms[i])
        {
            indx = i;
            break;
        }
    }
    switch (indx)
    {
    case 0:
        return new ShrubberyCreationForm(target);
    case 1:
        return new RobotomyRequestForm(target);
    case 2:
        return new PresidentialPardonForm(target);
    default:
        std::cerr <<" no such a Form"<<std::endl;
        return NULL;
        break;
    }
}
