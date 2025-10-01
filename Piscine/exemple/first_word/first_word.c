/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:22:47 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/10 14:53:07 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
/*
void putstring(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void putchar(char let)
{
	write(1, &let, 1);
}
*/
int main(int ac, char **av)
{
	int i = 0;
	if (ac != 2 || av[1][i] == '\0')
	{
		write(1, "\n", 1);
		return (0);
	}
	while (av[1][i] == ' ' || av[1][i] == '	')
		i++;
	while (av[1][i] != ' ' && av[1][i] != '	' && av[1][i])
	{
		write(1, &av[1][i], 1);
		i++;
	}
}
