




CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = bureaucrat

SRCS = main.cpp Bureaucrat.cpp

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all