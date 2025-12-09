#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try
    {
        Bureaucrat a("zakaria",15);
        Form form("form1",15,20);
        form.beSigned(a);
    }
    catch(const Bureaucrat::GradeTooLowException e)
    {
        std::cerr << e.what() << '\n';
    }
}
