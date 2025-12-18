#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm: public AForm
{
private:
    const std::string _target;
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm &src);
    ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
    void execute(Bureaucrat const &executor) ;
    std::string getTarget(void) const;
};


#endif