#include "PresidentialPardonForm.hpp"
PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout<<"default PresidentialPardonForm constructor has been called"<<std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout<<target<<" PresidentialPardonForm constructor has been called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) 
    : AForm(src), _target(src._target)
{
     std::cout<<"PresidentialPardonForm copy constructor has been called"<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
     std::cout<<"PresidentialPardonForm destructor has been called"<<std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    AForm::operator=(src);
     std::cout<<"PresidentialPardonForm assignment operator  has been called"<<std::endl;
    return *this;
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) 
{
    if (!GetIsSigned())
        throw AForm::NotSignedException();
    if (executor.GetGrade() > GetGradeExecute())
        throw AForm::GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    this->SetIsExecuted(true);
}
