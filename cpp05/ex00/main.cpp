#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("zakaria",151);
        std::cout<<a<<std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat b("kiro",0);
        std::cout<<b<<std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat c("niro",5);
        std::cout<<c<<std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException e)
    {
        std::cerr << e.what() << '\n';
    }
    
}