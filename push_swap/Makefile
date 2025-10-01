# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 12:17:25 by pde-vara          #+#    #+#              #
#    Updated: 2025/02/19 11:23:46 by pde-vara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC_DIR = src
SRC = operations.c tri_petit.c push_swap.c tri_radix.c parsing.c init_stacks.c operations2.c operations3.c
SRC := $(addprefix $(SRC_DIR)/, $(SRC))

# Object files
OBJ_DIR = obj
OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Libraries
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Include directories
INCLUDES = -I./includes -I$(LIBFT_DIR)

SILENT = @

GREEN = \033[0;32m
RESET = \033[0m

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
	$(SILENT)mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(SILENT)$(MAKE) -C $(LIBFT_DIR) > /dev/null

$(NAME): $(OBJS)
	$(SILENT)$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) successfully compiled!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(SILENT)mkdir -p $(dir $@)
	$(SILENT)$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(SILENT)$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	$(SILENT)rm -rf $(OBJ_DIR)
	@echo "$(GREEN)🧹 Object files cleaned!$(RESET)"

fclean: clean
	$(SILENT)$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	$(SILENT)rm -f $(NAME)
	@echo "$(GREEN)🗑️  All generated files cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
