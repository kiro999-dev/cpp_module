#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat a("zakaria", 15);
        Form form("form1", 15, 20);
        form.beSigned(a);
        std::cout << form << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Bureaucrat: " << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Bureaucrat: " << e.what() << '\n';
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << "Form: " << e.what() << '\n';
    }
    catch(const Form::GradeTooHighException& e)
    {
        std::cerr << "Form: " << e.what() << '\n';
    }
    return 0;
}