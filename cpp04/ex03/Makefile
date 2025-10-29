CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = AMateria.cpp  Character.cpp  Cure.cpp  Ice.cpp  main.cpp  MateriaSource.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS = AMateria.hpp  Character.hpp  Cure.hpp  Ice.hpp  ICharacter.hpp  IMateriaSource.hpp  MateriaSource.hpp
NAME = main

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
