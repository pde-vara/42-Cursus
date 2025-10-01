/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:20:33 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/02 14:48:08 by pde-vara         ###   ########.fr       */
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
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ft_is_prime(atoi(argv[1])));
	return 0;
}*/
