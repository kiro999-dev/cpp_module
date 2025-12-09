#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat():_name("unknown"),_grade(150)
{
}
Bureaucrat::Bureaucrat(std::string name,short gread):_name(name)
{
    if(gread < 1)
        throw GradeTooHighException();
    else if(gread > 150)
        throw GradeTooLowException();
    else
        _grade = gread;
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
}
Bureaucrat::GradeTooHighException::GradeTooHighException()
{
    
}
const char *Bureaucrat::GradeTooHighException::what()
{
    return "Grade Too High";
}
const char *Bureaucrat::GradeTooLowException::what()
{
    return "Grade Too Low";
}

Bureaucrat::~Bureaucrat()
{
    std::cout<<"destructor has been called"<<std::endl;
}
const std::string& Bureaucrat::GetName() const
{
    return _name;
}
const short&Bureaucrat::GetGrade() const
{
    return _grade;
}
void Bureaucrat::IncGrade()
{
    if(_grade == 1)
        throw GradeTooHighException();
    else
        _grade--;
}
void Bureaucrat::DecGrade()
{
    if(_grade == 150)
        throw GradeTooLowException();
    else
        _grade++;
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os<<obj.GetName()<<", bureaucrat grade "<<obj.GetGrade();
    return os;
}
 