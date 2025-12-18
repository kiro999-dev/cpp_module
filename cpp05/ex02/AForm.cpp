#include "AForm.hpp"
#include "Bureaucrat.hpp"
AForm::AForm():_Name("Boss AForm"),_IsSigned(false),_IsExecuted(false),
_GradeSign(1),
_GradeExecute(1)
{}
AForm::AForm(std::string name,short gradeSign,short gradeExecute):_Name(name),_IsSigned(false),_IsExecuted(false),
_GradeSign(gradeSign),
_GradeExecute(gradeExecute)
{
    if(gradeExecute > 150 || gradeSign > 150)
        throw GradeTooLowException();
    if(gradeExecute < 1 || gradeSign < 1)
        throw GradeTooHighException();
}
AForm::AForm(const AForm &other):_Name(other._Name),_IsSigned(other._IsSigned),_IsExecuted(other._IsExecuted),
_GradeSign(other._GradeSign),
_GradeExecute(other._GradeExecute)
{
}
 AForm& AForm::operator=(const AForm&other)
{
    _IsSigned = other._IsSigned;
    _IsExecuted = other._IsExecuted;
    return *this;
}
const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}
const std::string &AForm::GetName() const
{
    return _Name;
}
bool  AForm::GetIsSigned() const
{
    return _IsSigned;
}
bool  AForm::GetIsExecuted() const
{
    return _IsExecuted;
}
const short& AForm::GetGradeSign() const
{
    return _GradeSign;
}
const short& AForm::GetGradeExecute() const
{
    return _GradeExecute;
}
void  AForm::SetIsSigned(bool fact)
{
    _IsSigned = fact;
}
void  AForm::SetIsExecuted(bool fact)
{
    _IsExecuted = fact;
}
AForm::GradeTooLowException::GradeTooLowException()
{

}
AForm::GradeTooHighException::GradeTooHighException()
{

}
std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os<<"NAME: "<<obj.GetName()<<std::endl;
    os<<"IS SIGNED: "<<(obj.GetIsSigned() ? "YES" : "NO"); 
    os <<std::endl;
    os<<"GRADE REQUIRED TO SIGN IT: "<<obj.GetGradeSign()<<std::endl;
    os<<"GRADE REQUIRED TO EXECUTE IT: "<<obj.GetGradeExecute()<<std::endl;
    return os;
}
void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.GetGrade() > _GradeSign)
        throw GradeTooLowException();
    else
        _IsSigned = true;
    
}
void AForm::beExecuted(Bureaucrat &bureaucrat)
{
    if(bureaucrat.GetGrade() > _GradeExecute)
        throw GradeTooLowException();
    else
        _IsExecuted = true;
    
}
AForm::~AForm(){}
