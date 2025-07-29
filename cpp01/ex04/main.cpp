#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::string s2;
	std::string s1;
	std::string str;
	int index;
	int i;

	i = 0;
	index = 0;
	s1 = argv[2];
	s2 = argv[3];
	std::string new_str = "";
	if (argc != 4)
	{
		std::cout << "bad input try [filename s1 s2]" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	if (file.is_open())
	{
		while (std::getline(file, str))
		{
			if (index != std::string::npos)
			{
				while (index != std::string::npos)
				{
					i = 0;
					while (i < s1.length() || i < s2.length())
					{
						str[index] = s2[i];
						index++;
						i++;
					}
					index = str.find(argv[2]);
				}
			}
			new_str += str;
			new_str += "\n";
		}
		std::cout << new_str;
		file.close();
	}
	else
	{
		std::cout << "Erorr opening file" << std::endl;
	}
}