#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("zakaria",150);
        std::cout<<a<<std::endl;
        a.IncGrade();
        std::cout<<a<<std::endl;
        a.DecGrade();
        std::cout<<a<<std::endl;
        a.DecGrade();
        std::cout<<a<<std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
   
    catch(const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    
}