


CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = brain

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all