#include "PhoneBook.hpp"

PhoneBook::PhoneBook():index(0),size(0)
{
}
int PhoneBook::getIndex()
{
	return (index);
}
void PhoneBook::setIndex()
{
	index++;
}
int PhoneBook::getSize()
{
	return (size);
}
bool check_names(std::string str)
{
	size_t i = 0;
	while (i < str.length())
	{
		if(!std::isalpha(str[i]))
			return true;
		i++;
	}
	return false;
}
void PhoneBook::setSize()
{
	if(size < 8)
		size++;
}
void PhoneBook::ADD()
{
	int index = getIndex();
	Contacts contact;
	system("clear");
	std::string str;

	std::cout<<"enter first name:"<<std::endl;
	if(safegetline(str))
		return;
	if(check_names(str))
	{
		std::cout<<"Name must contain letters only. Please try again."<<std::endl;
		return;
	}
	contact.SetFirstName(str);
	std::cout<<"enter last name:"<<std::endl;

	if(safegetline(str))
		return;
	if(check_names(str))
	{
		std::cout<<"Name must contain letters only. Please try again."<<std::endl;
		return;
	}
	contact.SetLastName(str);
	std::cout<<"enter nick name:"<<std::endl;
	if(safegetline(str))
		return;
	contact.SetNickName(str);

	std::cout<<"enter phone number:" <<std::endl;
	if(safegetline(str))
		return;
	if(check_is_number(str))
	{
		std::cout<<"Please enter a number"<<std::endl;
		return;
	}
	contact.SetPhoneNumber(str);
	std::cout<<"enter darkest secret:" <<std::endl;
	if(safegetline(str))
		return;
	contact.SetDarkSecret(str);
	arr[index%8] = contact;
	setIndex();
	setSize();
	system("clear");
}
void trunc_str(std::string& str)
{
	if(str.size() > 10)
	{
		str = str.substr(0, 9);
		str += ".";
	}
}
void PhoneBook::Search()
{
	if(getSize() == 0)
	{
		system("clear");
		std::cout<<"empty contact... try add some contacts"<<std::endl;
		return;
	}
	int i = 0;
	int SearchIndex;
	std::string str;
	std::string Firstname;
	std::string Lastname;
	std::string Nickname;

	std::cout << "|"  <<  std::setw(10) << "index"<<"|"
		<< std::setw(10) << "firstName"<<"|"
		<< std::setw(10) << "lastName" <<"|"
		<< std::setw(10) << "nickName"<<"|"
	<< std::endl;
	while (i < getSize())
	{
		Firstname = arr[i].GetFirstName();
		trunc_str(Firstname);
		Lastname = arr[i].GetLastName();
		trunc_str(Lastname);
		Nickname = arr[i].GetNickName();
		trunc_str(Nickname);
		std::cout << "|" << std::setw(10) << i
		<< "|" << std::setw(10) << Firstname
		<< "|" << std::setw(10) << Lastname
		<< "|" << std::setw(10) << Nickname
		<< "|" << std::endl;
		i++;
	}
	std::cout<<"Enter the index you want to search."<<std::endl;
	if(safegetline(str))
		return;
	if(check_is_number(str))
	{
		std::cout<<"Please enter a valid index[0-7]."<<std::endl;
		return ;
	}
	if(str.length() > 1)
	{
		std::cout<<"Please enter one digit [0-9]"<<std::endl;
		return ;
	}
	SearchIndex = std::atoi(str.c_str());
	std::cout<<SearchIndex<<std::endl;
	if(SearchIndex < 0)
	{
		std::cout<<"Please enter a valid index[0-7]."<<std::endl;
		return ;
	}
	if(SearchIndex > getSize() - 1)
	{
		std::cout<<"out of range"<<std::endl;
		return;
	}
	
	system("clear");
	std::cout<<"first name: " <<arr[SearchIndex].GetFirstName()<<std::endl;
	std::cout<<"last name: " <<arr[SearchIndex].GetLastName()<<std::endl;
	std::cout<<"nick name: " <<arr[SearchIndex].GetNickName()<<std::endl;
	std::cout<<"phone number: " <<arr[SearchIndex].GetPhoneNumber()<<std::endl;
	std::cout<<"darkest secret: " <<arr[SearchIndex].GetDarkSecret()<<std::endl;
}
bool check_is_number(std::string str)
{
	size_t i = 0;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
		{
			return(true);
		}
		i++;
	}
	return false;
}
bool check_input(std::string str)
{
	size_t  i = 0;
	while (i < str.length())
	{
		if (!std::isprint(str[i]))
		{
			return(true);
		}
		i++;
	}
	return false;
}
bool safegetline(std::string &str)
{
	std::getline(std::cin, str);
	if (std::cin.eof())
		{
			std::cout<<"exting..."<<std::endl;
			exit(1);
		}
	if(str.empty() || check_input(str))
	{
		std::cout<<"bad input(empty or non printable input)"<<std::endl;
		return (true);
	}
	return (false);
}
