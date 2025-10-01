# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 18:37:27 by pde-vara          #+#    #+#              #
#    Updated: 2024/11/08 18:42:28 by pde-vara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fr_display_file.c

SRC = fr_display_file.c
OBJ = $(SRC:.c=o)

CC = cc
CFLAGS - -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(Cflags) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all