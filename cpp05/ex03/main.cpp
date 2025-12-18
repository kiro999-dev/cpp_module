#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
    try
    {
        Bureaucrat a("zakaria", 5);
        Bureaucrat b("kiro", 30);
        ShrubberyCreationForm s("soso");
        std::cout<<s;
        AForm *shrubbery = new ShrubberyCreationForm("tree");
        AForm *robot = new RobotomyRequestForm("robot");
        AForm *prisdent = new PresidentialPardonForm("President");
        shrubbery->beSigned(a);
        shrubbery->execute(b);
        robot->beSigned(a);
        robot->execute(b);
        prisdent->beSigned(a);
        prisdent->execute(a);
        std::cout << *shrubbery << std::endl;
        std::cout << *robot << std::endl;
        std::cout << *prisdent << std::endl;
        delete shrubbery;
        delete robot;
        delete prisdent;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Bureaucrat: " << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Bureaucrat: " << e.what() << '\n';
    }
    catch(const AForm::GradeTooLowException& e)
    {
        std::cerr << "AForm: " << e.what() << '\n';
    }
    catch(const AForm::GradeTooHighException& e)
    {
        std::cerr << "AForm: " << e.what() << '\n';
    }
    return 0;
}