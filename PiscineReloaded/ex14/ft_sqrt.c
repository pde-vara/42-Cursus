/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:31:58 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/05 14:55:05 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	while (n * n < nb)
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
