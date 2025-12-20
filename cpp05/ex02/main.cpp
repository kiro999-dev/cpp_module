
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
void cleanupForms(AForm* rrf, AForm* shrubbery, AForm* robot, AForm* prisdent)
{
    delete rrf;
    delete shrubbery;
    delete robot;
    delete prisdent;
}

int main()
{
    AForm *shrubbery = NULL;
    AForm *robot = NULL;
    AForm *prisdent = NULL;
    AForm *rrf = NULL;
    
    try
    {
        Bureaucrat a("zakaria", 5);
        Bureaucrat b("kiro", 30);
        shrubbery = new ShrubberyCreationForm("tree");
        robot = new RobotomyRequestForm("robot");
        prisdent = new PresidentialPardonForm("President");
        
        shrubbery->beSigned(a);
        shrubbery->execute(b);
        robot->beSigned(a);
        robot->execute(b);
        prisdent->beSigned(a);
        prisdent->execute(a);
        
        std::cout << *shrubbery << std::endl;
        std::cout << *robot << std::endl;
        std::cout << *prisdent << std::endl;
        cleanupForms(rrf, shrubbery, robot, prisdent);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
        cleanupForms(rrf, shrubbery, robot, prisdent);
    }
    catch (...)  
    {
        std::cerr << "Unknown exception occurred\n";
        cleanupForms(rrf, shrubbery, robot, prisdent);
    }
    
    return 0;
}