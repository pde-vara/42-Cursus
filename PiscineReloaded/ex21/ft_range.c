/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:00:05 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/06 10:47:43 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;
	int	lentab;

	lentab = max - min;
	i = 0;
	if (min >= max)
		return (NULL);
	tab = malloc(lentab * sizeof(int));
	if (!tab)
		return (NULL);
	while (i < lentab)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	int i = 0;
        int *fifi;

        fifi = ft_range(atoi(argv[1]), atoi(argv[2]));
        while (fifi[i])
        {
                printf("%d, ", fifi[i]);
                i++;
        }
        free(fifi);

}

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
