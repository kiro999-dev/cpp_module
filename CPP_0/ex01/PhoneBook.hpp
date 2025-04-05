#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
class PhoneBook
{
private:
	int curr_index;
	int	nb_contact;
	Contact contacts [8];
public:
			PhoneBook();
			~PhoneBook();
	void	add_contact();
	void	search();
};

#endif