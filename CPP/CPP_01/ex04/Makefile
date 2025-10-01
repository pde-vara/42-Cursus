


NAME = sed

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)
	@echo "= clean"

re: fclean all
