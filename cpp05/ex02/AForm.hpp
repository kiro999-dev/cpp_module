#ifndef AForm_HPP
#define AForm_HPP
#include <iostream>

class Bureaucrat;
class AForm
{
private:
    const std::string _Name;
    bool _IsSigned;
    bool _IsExecuted;
    const short _GradeSign;
    const short _GradeExecute;
public:
    AForm(std::string,short,short);
    AForm();
    AForm(const AForm&other);
    AForm &operator=(const AForm&other);
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
    virtual ~AForm();
    const std::string &GetName() const;
    bool  GetIsSigned() const;
    bool  GetIsExecuted() const;
    const short& GetGradeSign() const;
    const short& GetGradeExecute() const;
    void  SetIsSigned(bool );
    void  SetIsExecuted(bool );
    void  beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) = 0 ;
};
std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif