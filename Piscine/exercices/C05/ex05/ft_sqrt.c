/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:46:40 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/01 21:16:20 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	while (n * n < nb && n < 46341)
		n++;
	if (n * n == nb)
		return (n);
	else
		return (0);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_sqrt(atoi(argv[1])));
}*/
