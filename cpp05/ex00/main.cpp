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
   
    catch(const Bureaucrat::GradeTooHighException e)
    {
        std::cerr << e.what() << '\n';
    }
    
}