SRC = Contact.cpp PhoneBook.cpp main.cpp
NAME = PhoneBook
CC = c++ -Wall -Wextra -Werror -std=c++98
INC =  Contact.hpp PhoneBook.hpp main.hpp
all: $(NAME)

$(NAME): $(SRC) $(INC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all