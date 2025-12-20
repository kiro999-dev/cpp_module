#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
void cleanupForms(AForm* rrf, AForm* shrubbery, AForm* prisdent)
{
    delete rrf;
    delete shrubbery;
    delete prisdent;
}

int main()
{
    AForm *shrubbery = NULL;
    AForm *prisdent = NULL;
    AForm *rrf = NULL;
    std::srand(std::time(NULL));
    
    try
    {
        Intern someRandomIntern;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat a("zakaria", 5);
        Bureaucrat b("kiro", 30);
        
        if (rrf)
        {
            std::cout<<*rrf;
            rrf->beSigned(a);
            rrf->execute(a);
        }
        
        shrubbery = new ShrubberyCreationForm("tree");
        prisdent = new PresidentialPardonForm("President");
        shrubbery->beSigned(a);
        shrubbery->execute(b);
        prisdent->beSigned(a);
        prisdent->execute(a);
        std::cout << *shrubbery << std::endl;
        std::cout << *prisdent << std::endl;
        cleanupForms(rrf, shrubbery, prisdent);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
        cleanupForms(rrf, shrubbery, prisdent);
    }
    catch (...)  
    {
        std::cerr << "Unknown exception occurred\n";
        cleanupForms(rrf, shrubbery, prisdent);
    }
    
    return 0;
}