




CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = form

SRCS = main.cpp Bureaucrat.cpp Form.cpp

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all