/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:09:10 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/05 12:19:54 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int main(void)
{
	int x;
	int y;
	int div;
	int mod;
	x = 15;
	y = 4;
	ft_div_mod(x, y, &div, &mod);
	printf("%d divise par %d fait %d modulo %d", x, y, div, mod);
	return (0);
}*/
