#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm: public AForm
{
private:
    const std::string _target;
public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm &src);
    ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
    void execute(Bureaucrat const &executor) ;
    std::string getTarget(void) const;
};


#endif