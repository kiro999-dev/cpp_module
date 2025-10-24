SRC = main.cpp ClapTrap.cpp  ScavTrap.cpp FragTrap.cpp
OBJ = $(SRC:.cpp=.o)
NAME = main
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
headers = ScavTrap.hpp  ClapTrap.hpp FragTrap.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp $(headers)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all