

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = converter

SRCS = main.cpp ScalarConverter.cpp

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all