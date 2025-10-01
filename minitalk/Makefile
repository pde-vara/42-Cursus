# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 11:55:17 by pde-vara          #+#    #+#              #
#    Updated: 2025/02/21 14:02:58 by pde-vara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Dossiers
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = ./libft

# Fichiers source
SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_SERVER := $(addprefix $(SRC_DIR)/, $(SRC_SERVER))
SRC_CLIENT := $(addprefix $(SRC_DIR)/, $(SRC_CLIENT))

# Fichiers objets
OBJ_SERVER = $(SRC_SERVER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_CLIENT = $(SRC_CLIENT:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Bibliothèque Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Headers
INCLUDES = -I./includes -I$(LIBFT_DIR)

# Couleurs
GREEN = \033[1;38;5;82m
RESET = \033[1;0m

# Compilation principale
all: $(LIBFT) server client

server: $(OBJ_SERVER) $(LIBFT)
	$(SILENT)$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ_SERVER) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)✅ server compiled successfully!$(RESET)"

client: $(OBJ_CLIENT) $(LIBFT)
	$(SILENT)$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ_CLIENT) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)✅ client compiled successfully!$(RESET)"

# Création du dossier des objets
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
SILENT = @

# Compilation de la libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Nettoyage
clean:
	$(SILENT)$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	$(SILENT)rm -rf $(OBJ_DIR)
	$(SILENT)echo "$(GREEN)🧹 Object files cleaned!$(RESET)"

fclean: clean
	$(SILENT)$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	$(SILENT)rm -f server client
	$(SILENT)echo "$(GREEN)🗑️  All generated files cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re