CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror  -std=c++98

NAME    = btc

SRC     = main.cpp ParsingData.cpp BitcoinExchange.cpp Date.cpp
OBJ     = $(SRC:.cpp=.o)

HEADERS = Date.hpp BitcoinExchange.hpp  main.hpp

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
