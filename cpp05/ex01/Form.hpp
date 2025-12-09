#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

class Bureaucrat;
class Form
{
private:
    const std::string _Name;
    bool _IsSigned;
    const short _GradeSign;
    const short _GradeExecute;
public:
    Form(std::string,short,short);
    Form();
    Form(const Form&other);
    Form &operator=(const Form&other);
    class GradeTooHighException : public std::exception
    {
        public:
            GradeTooHighException();
           virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            GradeTooLowException();
           virtual const char *what()  const throw();
    };
    ~Form();
    const std::string &GetName() const;
    bool  GetIsSigned() const;
    const short& GetGradeSign() const;
    const short& GetGradeExecute() const;
    void  SetIsSigned(bool );
    void  beSigned(Bureaucrat &bureaucrat);
};
std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif