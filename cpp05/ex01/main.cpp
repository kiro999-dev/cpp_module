#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat a("zakaria", 15);
        Bureaucrat b("kiro",25);
        Form form("form1", 15, 20);
        Form form2("form2", 20, 20);
        form.beSigned(a);
        std::cout << form << std::endl;
        form2.beSigned(b);
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
      catch(const std::exception & e)
    {
        std::cerr << "exception: " << e.what() << '\n';
    }
    return 0;
}