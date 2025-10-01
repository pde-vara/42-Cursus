




CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = form

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
		rm -f home_shrubbery

re: fclean all