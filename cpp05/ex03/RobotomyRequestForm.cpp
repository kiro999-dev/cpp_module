#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), _target(src._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    AForm::operator=(src);
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

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *a)
{
    o << "RobotomyRequestForm: " << a->getTarget();
    return o;
}