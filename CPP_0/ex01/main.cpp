#include "PhoneBook.hpp"
int main()
{
	PhoneBook phonebook;
	std::string add= "ADD";
	std::string search = "SEARCH";
	std::string exit = "EXIT";
	std::string line;
	std::cout<<"HI WELCOME TO THE PHONEBOOK"<<std::endl;
	while (1)
	{
		std::cout <<"ENTER ADD OR SEARCH OR EXIT : ";
		std::getline(std::cin,line);
	   	if(!line.compare(add))
			phonebook.add_contact();
		else if (!line.compare(search))
			phonebook.search();
		else if(!line.compare(exit))
			break;
		system("clear");
	}
	std::cout <<"Good bye:)\n";
	return(0);
}