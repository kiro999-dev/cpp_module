
#include "Contact.hpp"
Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

void Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}

void Contact::set_nick_name(std::string nick_name)
{
    this->nick_name = nick_name;
}

void Contact::set_secret(std::string secret)
{
    this->secret = secret;
}

void Contact::set_phone_number(std::string phone_number)
{
    this->phone_number = phone_number;
}

std::string Contact::get_first_name() const
{
   return (this->first_name);
}

std::string Contact::get_last_name() const
{
    return(this->last_name);
}

std::string Contact::get_nick_name() const
{
    return(this->nick_name);
}

std::string Contact::get_secret() const
{
     return(this->secret);
}

std::string Contact::get_phone_number() const 
{
     return(this->phone_number);
}
