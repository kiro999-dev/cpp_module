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
AForm *Intern::makeForm(std::string &formName, std::string &target)
{
    std::string Forms[3]="";
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

        break;
    case 2:

        break;
    case 3:

        break;
    default:
        throw CreatFormError();
        break;
    }
}
