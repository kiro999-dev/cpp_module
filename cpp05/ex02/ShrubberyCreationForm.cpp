#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145,137), _target("default")
{
    std::cout<<"default ShrubberyCreationForm constructor has been called"<<std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout<<target<<" ShrubberyCreationForm constructor has been called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) 
    : AForm(src), _target(src._target)
{
     std::cout<<"ShrubberyCreationForm copy constructor has been called"<<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
     std::cout<<"ShrubberyCreationForm destructor has been called"<<std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    AForm::operator=(src);
     std::cout<<"ShrubberyCreationForm assignment operator  has been called"<<std::endl;
    return *this;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) 
{
    if (!GetIsSigned())
        throw AForm::NotSignedException();
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
    this->SetIsExecuted(true);
}
