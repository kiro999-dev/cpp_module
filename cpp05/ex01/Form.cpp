#include "Form.hpp"
#include "Bureaucrat.hpp"
Form::Form() : _Name("Boss Form"), _IsSigned(false), _IsExecuted(false),
               _GradeSign(1),
               _GradeExecute(1)
{
}
Form::Form(const std::string &name, short gradeSign, short gradeExecute) : _Name(name), _IsSigned(false), _IsExecuted(false),
                                                                     _GradeSign(gradeSign),
                                                                     _GradeExecute(gradeExecute)
{
    if (gradeExecute > 150 || gradeSign > 150)
        throw GradeTooLowException();
    if (gradeExecute < 1 || gradeSign < 1)
        throw GradeTooHighException();
}
Form::Form(const Form &other) : _Name(other._Name), _IsSigned(other._IsSigned), _IsExecuted(other._IsExecuted),
                                _GradeSign(other._GradeSign),
                                _GradeExecute(other._GradeExecute)
{
}
Form &Form::operator=(const Form &other)
{
    if(this == &other)
        return *this;
    _IsSigned = other._IsSigned;
    _IsExecuted = other._IsExecuted;
    return *this;
}
const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}
const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}
const std::string &Form::GetName() const
{
    return _Name;
}
bool Form::GetIsSigned() const
{
    return _IsSigned;
}
bool Form::GetIsExecuted() const
{
    return _IsExecuted;
}
short Form::GetGradeSign() const
{
    return _GradeSign;
}
short Form::GetGradeExecute() const
{
    return _GradeExecute;
}
void Form::SetIsSigned(bool fact)
{
    _IsSigned = fact;
}
void Form::SetIsExecuted(bool fact)
{
    _IsExecuted = fact;
}
Form::GradeTooLowException::GradeTooLowException()
{
}
Form::GradeTooHighException::GradeTooHighException()
{
}
std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << "NAME: " << obj.GetName() << std::endl;
    os << "IS SIGNED: " << (obj.GetIsSigned() ? "YES" : "NO");
    os << std::endl;
    os << "GRADE REQUIRED TO SIGN IT: " << obj.GetGradeSign() << std::endl;
    os << "GRADE REQUIRED TO EXECUTE IT: " << obj.GetGradeExecute() << std::endl;
    return os;
}
void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.GetGrade() > _GradeSign)
        throw GradeTooLowException();
    else
        _IsSigned = true;
}

Form::~Form()
{
    std::cout << "Form destructor has been called" << std::endl;
}
