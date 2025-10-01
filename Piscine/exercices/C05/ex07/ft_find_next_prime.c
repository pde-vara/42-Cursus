/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:44:26 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/03 14:45:23 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb)
{
	int	n;

	n = 2;
	if (nb < 2)
		return (0);
	while (n <= nb / n)
	{
		if (nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 0;
	if (nb <= 2)
		return (2);
	while (!(ft_is_prime(nb + i)))
		i++;
	return (nb + i);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_find_next_prime(atoi(argv[1])));
	return 0;
}*/
