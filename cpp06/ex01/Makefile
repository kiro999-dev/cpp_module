CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp  Serializer.cpp
OBJ = $(SRC:.cpp=.o)

HEADERS = main.hpp Serializer.hpp

NAME = Serializer

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
