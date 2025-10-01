/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:05:42 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/01 11:51:21 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
	int	fac;

	fac = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb != 1)
	{
		fac = fac * (nb - 1);
		nb--;
	}
	return (fac);
}
/*
int main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ft_iterative_factorial(atoi(argv[1])));
}*/
