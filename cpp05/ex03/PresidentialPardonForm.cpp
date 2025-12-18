#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) 
    : AForm(src), _target(src._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    AForm::operator=(src);
    return *this;
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) 
{
    if (!GetIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.GetGrade() > GetGradeExecute())
        throw AForm::GradeTooLowException();
    
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a)
{
    o << "PresidentialPardonForm: " << a->getTarget();
    return o;
}