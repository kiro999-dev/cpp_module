#include "Form.hpp"
#include "Bureaucrat.hpp"
Form::Form():_Name("Boss Form"),_IsSigned(0),
_GradeSign(1),
_GradeExecute(1){}
Form::Form(std::string name,short gradeSign,short gradeExecute):_Name(name),_IsSigned(false),
_GradeSign(gradeSign),
_GradeExecute(gradeExecute)
{
    if(gradeExecute > 150 || gradeSign > 150)
        throw GradeTooLowException();
    if(gradeExecute < 1 || gradeSign < 1)
        throw GradeTooHighException();
}
Form::Form(const Form &other):_Name(other._Name),_IsSigned(other._IsSigned),
_GradeSign(other._GradeSign),
_GradeExecute(other._GradeExecute)
{
}
 Form& Form::operator=(const Form&other)
{
    _IsSigned = other._IsSigned;
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
bool  Form::GetIsSigned() const
{
    return _IsSigned;
}
const short& Form::GetGradeSign() const
{
    return _GradeSign;
}
const short& Form::GetGradeExecute() const
{
    return _GradeExecute;
}
void  Form::SetIsSigned(bool fact)
{
    _IsSigned = fact;
}
std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os<<"NAME: "<<obj.GetName()<<std::endl;
    os<<"IS SIGNED: "<<(obj.GetIsSigned() ? "YES" : "NO"); 
    os <<std::endl;
    os<<"GRADE REQUIRED TO SIGN IT: "<<obj.GetGradeSign()<<std::endl;
    os<<"GRADE REQUIRED TO EXECUTE IT: "<<obj.GetGradeSign()<<std::endl;
    return os;
}
void Form::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.GetGrade() > _GradeSign)
        throw GradeTooLowException();
    else
        _IsSigned = true;
    
}
Form::~Form(){}
