#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"
#include <string>
#include <iomanip>
class PhoneBook
{
private:
    Contacts arr[8];
    int index;
	int size;
public:
	PhoneBook();
	int		getIndex();
	void	setIndex();
	int		getSize();
	void	setSize();
	void ADD();
	void Search();
	
};
bool check_is_number(std::string str);
bool safegetline(std::string &str);
#endif