#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "bad input try [filename s1 s2]" << std::endl;
		return 1;
	}
	std::string s2;
	std::string s1;
	std::string str;
	std::string filename;
	std::string filename_re;
	std::string new_str = "";
	size_t index;
	int i;

	i = 0;
	index = 0;
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	std::ifstream file(filename.c_str());
	filename_re = filename + ".replace";
	if (file.is_open())
	{
		while (std::getline(file, str,'\0'))
		{
			std::cout<<str<<std::endl;
			index = str.find(s1);
			while (index != std::string::npos && !s1.empty())
			{
				str.erase(index, s1.length());
				str.insert(index, s2);
				index = str.find(s1, index + s2.length());
			}
			new_str += str;
			if (!file.eof())
				new_str += "\n";
		}
		file.close();
		std::ofstream filereplace(filename_re.c_str());
		if (filereplace.is_open())
			filereplace << new_str;
		else
		{
			std::cout << "Erorr opening file" << std::endl;
		}
		filereplace.close();
	}
	else
	{
		std::cout << "Erorr opening file" << std::endl;
	}
}