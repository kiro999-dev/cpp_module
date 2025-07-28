#include "Contact.hpp"

void Contacts::SetFirstName(std::string s_first_name)
{
    this->first_name=s_first_name;
}
void Contacts::SetLastName(std::string s_last_name)
{
    this->last_name=s_last_name;
}
void Contacts::SetNickName(std::string nickname)
{
    this->nickname=nickname;
}
void Contacts::SetPhoneNumber(std::string phone_number)
{
    this->phone_number=phone_number;
}
void Contacts::SetDarkSecret(std::string s_dark_secret)
{
    this->dark_secret=s_dark_secret;
}
std::string& Contacts::GetFirstName()
{
    return(this->first_name);
}
std::string& Contacts::GetLastName()
{
    return(this->last_name);
}
std::string& Contacts::GetPhoneNumber()
{
    return(this->phone_number);
}
std::string& Contacts::GetDarkSecret()
{
    return(this->dark_secret);
}
std::string& Contacts::GetNickName()
{
    return(this->nickname);
} 