SRC = main.cpp Fixed.cpp
OBJ = $(SRC:.cpp=.o)
NAME = main
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
Header = Fixed.hpp
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp $(Header)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
