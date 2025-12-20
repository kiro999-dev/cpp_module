#include "Bureaucrat.hpp"
#include "Form.hpp"
Bureaucrat::Bureaucrat():_name("solder"),_grade(150)
{
}
Bureaucrat::Bureaucrat(const std::string &name, short grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        _grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}
Bureaucrat::GradeTooLowException::GradeTooLowException(){}
Bureaucrat::GradeTooHighException::GradeTooHighException(){}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor has been called" << std::endl;
}
const std::string &Bureaucrat::GetName() const
{
    return _name;
}
short Bureaucrat::GetGrade() const
{
    return _grade;
}
void Bureaucrat::IncGrade()
{
    if (_grade == 1)
        throw GradeTooHighException();
    else
        _grade--;
}
void Bureaucrat::DecGrade()
{
    if (_grade == 150)
        throw GradeTooLowException();
    else
        _grade++;
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.GetName() << ", bureaucrat grade " << obj.GetGrade();
    return os;
}
void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.GetName() << std::endl;
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cout << _name << " couldn't sign " << form.GetName()
                  << " because " << e.what() << std::endl;
    }
}
