#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <iostream>
class Bureaucrat
{
private:
    const std::string _name;
    short _grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string name,short grade);
    ~Bureaucrat();
    class GradeTooHighException : public std::exception
    {
        public:
            GradeTooHighException();
           virtual const char *what() noexcept;
    };
    class GradeTooLowException : public std::exception
    {
        public:
            GradeTooLowException();
           virtual const char *what() noexcept;
    };
    const std::string &GetName() const;
    const short&GetGrade() const;
    void IncGrade();
    void DecGrade();
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif