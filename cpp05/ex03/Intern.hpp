#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern
{
private:
    
public:
   AForm *makeForm(std::string&,std::string&);
   Intern();
   Intern(Intern &other);
   Intern operator=(Intern &o);
   class CreatFormError : public std::exception
   {
    public:
        virtual const char *what() const throw();
   };
   
   Intern::Intern(/* args */)
   {
   }
   
   Intern::~Intern()
   {
   }
   
   ~Intern();
};
