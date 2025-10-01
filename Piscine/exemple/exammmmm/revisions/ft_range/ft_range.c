/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:06:56 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/09 10:22:33 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
	int i;
	int *tab;
	int lentab;

	lentab = max - min;
	if (min >= max)
	{
		return (NULL);
	}
	tab = malloc(lentab * sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < lentab)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}

int main()
{
	int i = 0;
	int *tabl;

	tabl = ft_range(5, 16);
	while (tabl[i])
	{
		printf("%d\n", tabl[i]);
		i++;
	}
	free(tabl);
}
