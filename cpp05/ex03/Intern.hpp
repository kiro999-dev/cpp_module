#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern
{
private:
    
public:
   AForm *makeForm(const std::string&,const std::string&);
   Intern();
   Intern(const Intern &other);
   Intern &operator=(Intern &o);
   ~Intern();
};

#endif