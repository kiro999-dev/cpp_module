#include "AForm.hpp"
#include "Bureaucrat.hpp"
AForm::AForm() : _Name("Boss AForm"), _IsSigned(false), _IsExecuted(false),
                 _GradeSign(1),
                 _GradeExecute(1)
{
    std::cout<<"default AForm constructor has been called"<<std::endl;
}
AForm::AForm(const std::string name, short gradeSign, short gradeExecute) : _Name(name), _IsSigned(false), _IsExecuted(false),
                                                                            _GradeSign(gradeSign),
                                                                            _GradeExecute(gradeExecute)
{
    if (gradeExecute > 150 || gradeSign > 150)
        throw GradeTooLowException();
    if (gradeExecute < 1 || gradeSign < 1)
        throw GradeTooHighException();
    std::cout<<name<<" AForm constructor has been called"<<std::endl;
}
AForm::AForm(const AForm &other) : _Name(other._Name), _IsSigned(other._IsSigned), _IsExecuted(other._IsExecuted),
                                   _GradeSign(other._GradeSign),
                                   _GradeExecute(other._GradeExecute)
{
      std::cout<<" AForm  copy constructor has been called"<<std::endl;
}
AForm &AForm::operator=(const AForm &other)
{
    if(this == &other)
        return *this;
    _IsSigned = other._IsSigned;
    _IsExecuted = other._IsExecuted;
    std::cout<<" AForm  assignment operator has been called"<<std::endl;
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
const char *AForm::NotSignedException::what() const throw()
{
    return "Not Signed";
}
const std::string &AForm::GetName() const
{
    return _Name;
}
bool AForm::GetIsSigned() const
{
    return _IsSigned;
}
bool AForm::GetIsExecuted() const
{
    return _IsExecuted;
}
short AForm::GetGradeSign() const
{
    return _GradeSign;
}
short AForm::GetGradeExecute() const
{
    return _GradeExecute;
}
void AForm::SetIsSigned(bool fact)
{
    _IsSigned = fact;
}
void AForm::SetIsExecuted(bool fact)
{
    _IsExecuted = fact;
}
AForm::GradeTooLowException::GradeTooLowException()
{
}
AForm::GradeTooHighException::GradeTooHighException()
{
}
std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
    os << "NAME: " << obj.GetName() << std::endl;
    os << "IS SIGNED: " << (obj.GetIsSigned() ? "YES" : "NO");
    os << std::endl;
    os << "GRADE REQUIRED TO SIGN IT: " << obj.GetGradeSign() << std::endl;
    os << "GRADE REQUIRED TO EXECUTE IT: " << obj.GetGradeExecute() << std::endl;
    return os;
}
void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.GetGrade() > _GradeSign)
        throw GradeTooLowException();
    else
        _IsSigned = true;
}

AForm::~AForm() {
      std::cout<<"AForm destructor has been called"<<std::endl;
}
