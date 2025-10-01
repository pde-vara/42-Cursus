# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 10:20:51 by pde-vara          #+#    #+#              #
#    Updated: 2024/11/11 18:11:14 by pde-vara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

INCLUDES = includes/ft.h

OBJS = $(SRCS:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJS)
    ar rcs $(NAME) $(OBJS)

%.o: %.c $(INCLUDES)
    $(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
    rm -f $(OBJS)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
