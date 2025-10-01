/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:07:22 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/07 12:34:24 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	lentab;

	lentab = max - min;
	if (min >= max)
		return (NULL);
	tab = malloc((max - min) * sizeof(int));
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

/*
int	main()
{
	int i = 0;
	int *fifi;
	
	fifi = ft_range(10, 14);
	while (fifi[i])
	{
        	printf("%d, ", fifi[i]);
        	i++;
	}
	free(fifi);
}*/
