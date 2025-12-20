#include "RobotomyRequestForm.hpp"
RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout<<"default RobotomyRequestForm constructor has been called"<<std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout<<target<<" RobotomyRequestForm constructor has been called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) 
    : AForm(src), _target(src._target)
{
     std::cout<<"RobotomyRequestForm copy constructor has been called"<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
     std::cout<<"RobotomyRequestForm destructor has been called"<<std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    AForm::operator=(src);
     std::cout<<"RobotomyRequestForm assignment operator  has been called"<<std::endl;
    return *this;
}
std::string RobotomyRequestForm::getTarget(void) const
{
    return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)
{
    if (!GetIsSigned())
        throw AForm::NotSignedException();
    if (executor.GetGrade() > GetGradeExecute())
        throw AForm::GradeTooLowException();
    if (std::rand() % 2 == 0)
        std::cout << "beebboo bobobo beee " << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
    this->SetIsExecuted(true);
}
