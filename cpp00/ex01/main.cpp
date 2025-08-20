#include "PhoneBook.hpp"
int main()
{
	PhoneBook phone;
	std::string str;
	
	while (1)
	{
		std::cout<<"Enter [ADD] for adding contact,[SEARCH] for display them,[EXIT] for exiting "<<std::endl;
		safegetline(str);
		if (str.compare("ADD") == 0)
		{
			phone.ADD();
		}
		else if (str.compare("SEARCH") == 0)
		{
			phone.Search();
		}
		else if (str.compare("EXIT") == 0)
		{
			std::cout<<"exting..."<<std::endl;
			exit(0);
		}
		
	}
	return (0);
}
