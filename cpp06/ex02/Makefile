CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror 

NAME    = typeof

SRC     = main.cpp Base.cpp
OBJ     = $(SRC:.cpp=.o)

HEADERS = A.hpp B.hpp C.hpp Base.hpp 

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
