/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:30:10 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/04 11:04:05 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int ft_atoi(char *str)
{
	int i;
	int nb;
	int signe;

	i = 0;
	signe = 1;
	while (str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				signe = -signe;
			i++;
		}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * signe);
}

int main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ft_atoi(argv[1]));
}
