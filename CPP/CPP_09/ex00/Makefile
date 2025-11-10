# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 16:24:40 by lde-merc          #+#    #+#              #
#    Updated: 2025/07/04 14:20:06 by lde-merc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc
FLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRC = main.cpp BitcoinExchange.cpp
OBJDIR = objs
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32m$(NAME) created !\033[0m"
	
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@$(CPP) $(FLAGS) -c $< -o $@


clean:
	@rm -rf $(OBJDIR)
	@echo "\033[34mDeleting almost everything !\033[0m"
	
fclean: clean
	@rm -f $(NAME)
	@echo "\033[35mDeleting everything !\033[0m"
	
re: fclean all
	@echo "\033[33mmake re SUCCESS!\033[0m"

.PHONY: all clean fclean re