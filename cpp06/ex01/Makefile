CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp converter.cpp ScalarConverter.cpp
OBJ = $(SRC:.cpp=.o)

HEADERS = main.hpp  converter.hpp ScalarConverter.hpp

NAME = converte

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
