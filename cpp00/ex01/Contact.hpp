#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
class Contacts
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string dark_secret;
    public:
        void SetFirstName(std::string s_first_name);
        void SetLastName(std::string s_last_name);
        void SetNickName(std::string s_NickName);
        void SetPhoneNumber(std::string s_PhoneNumbe);
        void SetDarkSecret(std::string s_dark_secret);
        std::string& GetFirstName();
        std::string& GetLastName();
        std::string& GetNickName();
        std::string& GetPhoneNumber();   
        std::string& GetDarkSecret();
};
#endif