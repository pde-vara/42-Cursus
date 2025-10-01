/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:01:35 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/01 15:38:54 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	nbtemp;

	nbtemp = nb;
	i = 2;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (i <= power)
	{
		nb = nb * nbtemp;
		i++;
	}
	return (nb);
}
/*
int main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ft_iterative_power(atoi(argv[1]), (atoi(argv[2]))));
}*/
