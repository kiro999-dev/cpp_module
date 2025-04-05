#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : curr_index(0) ,nb_contact(0)
{

}
PhoneBook::~PhoneBook()
{
}

void    PhoneBook:: add_contact()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	secret;

	if(this->curr_index == 8)
		this->curr_index = 0;
	system("clear");
	std::cout <<"Enter first name: ";
	std::getline(std::cin,first_name);

	system("clear");
	std::cout <<"Enter last name: ";
	std::getline(std::cin,last_name);

	system("clear");
	std::cout <<"Enter nick name: ";
	std::getline(std::cin,nick_name);

	system("clear");
	std::cout <<"Enter phone number: ";
	std::getline(std::cin,phone_number);

	system("clear");
	std::cout <<"Enter secret: ";
	std::getline(std::cin,secret);

	this->contacts[this->curr_index].set_secret(secret);
	this->contacts[this->curr_index].set_first_name(first_name);
	this->contacts[this->curr_index].set_last_name(last_name);
	this->contacts[this->curr_index].set_nick_name(nick_name);
	this->contacts[this->curr_index].set_phone_number(phone_number);
	this->curr_index++;
	if(this->nb_contact < 8)
		this->nb_contact++;
}

void    PhoneBook:: search()
{
	int 		i;
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	secret;
	std::string line;

	i = 0;
	if (this->nb_contact == 0)
	{
		std::cout << "NO CONTACET AVALAIBLE! ABORTING ..."<<std::endl; 
		return ;
	}
	system("clear");
	std::cout <<std::setw(5)<<"Index" << "|";
	std::cout <<std::setw(10)<<"Firstname" << "|";
	std::cout <<std::setw(10)<<"Lastname" << "|";
	std::cout <<std::setw(10)<<"Nickname" << std::endl;
	while (i < this->nb_contact)
	{
		std::cout<<std::setw(5) << i << "|";
		first_name = this->contacts[i].get_first_name();
		last_name = this->contacts[i].get_last_name();
		nick_name = this->contacts[i].get_nick_name();
		if(first_name.length() > 9)
			first_name = first_name.substr(0,9) + '.';
		if(last_name.length() > 9)
			last_name = last_name.substr(0,9) + '.';
		if(nick_name.length() > 9)
			nick_name = nick_name.substr(0,9) + '.';
		std::cout<<std::setw(10) << first_name << "|";
		std::cout<<std::setw(10) << last_name << "|";
		std::cout<<std::setw(10) << nick_name << std::endl;
		i++;
	}
	std::cout <<"Enter the index you are searching for:";
	std::getline(std::cin,line);
	index = atoi(line.c_str());
	if((index=='0' && line[0] !='0') || (index > 7 || index < 0))
	{
		std::cout <<"NAH MAN ENTER A VALID INDEX PLEASE !";
		return;
	}
	std::cout << "Name : " << this->contacts[index].get_first_name() << std::endl;
	std::cout << "Lastname : " << this->contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname : " << this->contacts[index].get_nick_name() << std::endl;
	std::cout << "Phone number : " << this->contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest secret : " << this->contacts[index].get_secret() << std::endl;
	std::cout << std::endl << "Press a key to continue..." << std::endl;
	getchar();
	getchar();
}