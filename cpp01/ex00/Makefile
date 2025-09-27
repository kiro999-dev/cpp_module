SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp 
HEADERS = Zombie.hpp
OBJ = $(SRC:.cpp=.o)
NAME = Zombie
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
