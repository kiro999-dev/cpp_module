#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src) 
    : AForm(src), _target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    AForm::operator=(src);
    return *this;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) 
{
    if (!GetIsSigned())
        throw AForm::GradeTooLowException();
    if(executor.GetGrade() > this->GetGradeExecute())
        throw AForm::GradeTooLowException();
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }
    
    outfile << "       ###" << std::endl;
    outfile << "      #o###" << std::endl;
    outfile << "    #####o###" << std::endl;
    outfile << "   #o#\\#|#/###" << std::endl;
    outfile << "    ###\\|/#o#" << std::endl;
    outfile << "     # }|{  #" << std::endl;
    outfile << "       }|{" << std::endl;
    outfile << std::endl;
    outfile << "      .@@@." << std::endl;
    outfile << "    .@@@@@@@@." << std::endl;
    outfile << "  .@@@@@@@@@@@@." << std::endl;
    outfile << " .@@@@@@@@@@@@@@." << std::endl;
    outfile << ".@@@@@@@@@@@@@@@@@." << std::endl;
    outfile << "       ||||" << std::endl;
    outfile << "       ||||" << std::endl;
    
    outfile.close();
    std::cout << "Shrubbery has been planted at " << _target << std::endl;
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
    o << "ShrubberyCreationForm: " << a->getTarget();
    return o;
}