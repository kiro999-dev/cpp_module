#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <iostream>

class Form;
class Bureaucrat
{
private:
    const std::string _name;
    short _grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string &name,short grade);
    Bureaucrat(const Bureaucrat&other);
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();
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
    const std::string &GetName() const;
    const short&GetGrade() const;
    void signForm( Form& form) ;
    void ExecuteForm(Form& form);
    void IncGrade();
    void DecGrade();
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
