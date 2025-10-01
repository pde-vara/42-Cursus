# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 12:28:55 by pde-vara          #+#    #+#              #
#    Updated: 2025/03/17 19:52:06 by pde-vara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -g3


#-g3 -fsanitize=thread -static-libtsan

# Source files
SRC_DIR = src
SRC = philo.c parsing.c init.c checks.c main.c utils.c
SRC := $(addprefix $(SRC_DIR)/, $(SRC))

# Object files
OBJ_DIR = obj
OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Include directories
INCLUDES = -I./includes

SILENT = @

GREEN = \033[0;32m
RESET = \033[0m

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	$(SILENT)mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(SILENT)$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) successfully compiled!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(SILENT)mkdir -p $(dir $@)
	$(SILENT)$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(SILENT)rm -rf $(OBJ_DIR)
	@echo "$(GREEN)🧹 Object files cleaned!$(RESET)"

fclean: clean
	$(SILENT)rm -f $(NAME)
	@echo "$(GREEN)🗑️  All generated files cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re