/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:47:40 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/08 19:17:15 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	nbfinal;
	int	signe;

	i = 0;
	nbfinal = 0;
	signe = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbfinal = nbfinal * 10 + (str[i] - '0');
		i++;
	}
	return (nbfinal * signe);
}

int	main(int ac, char **av)
{
	ac = ac + 0;
	printf("%d\n", ft_atoi(av[1]));
	printf("%d\n", atoi(av[1]));
}
