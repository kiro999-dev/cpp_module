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
const char *Intern::CreatFormError::what() const throw()
{
    return "No such a Form";
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
    case 1:
        return new ShrubberyCreationForm(target);
    case 2:
        return new RobotomyRequestForm(target);
    case 3:
        return new PresidentialPardonForm(target);
    default:
        throw CreatFormError();
        break;
    }
}
