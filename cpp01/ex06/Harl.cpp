#include "Harl.hpp"
Harl::Harl()
{
}

Harl::~Harl()
{
}
void Harl::complain(std::string level)
{
	int i = 0;
	int index = -1;
	void (Harl::*func[4])(void);
	func[0] = &Harl::debug;
	func[1] = &Harl::info;
	func[2] = &Harl::warning;
	func[3] = &Harl::error;
	Harl harl;
	std::string complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4)
	{
		if (level == complains[i])
		{
			index = i;
			break;
		}
		i++;
	}
	switch (index)
	{
	case 0:
		(harl.*func[0])();
		break;
	case 1:
		(harl.*func[1])();
		break;
	case 2:
		(harl.*func[2])();;
		break;
	case 3:
		(harl.*func[3])();
	default:
		std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
		break;
	}
}
void Harl::debug(void)
{
	std::cout << "[debug]:I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "[info]:I cannot believe adding extra bacon costs more money."<<std::endl;
	std::cout<<"You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "[warning]:I think I deserve to have some extra bacon for free."<<std::endl;
	std::cout <<"I've been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << "[error]:This is unacceptable! I want to speak to the manager now." << std::endl;
}