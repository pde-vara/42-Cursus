/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:16:54 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/09 17:44:41 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (min < max)
	{
		range[0][i] = min;
		min++;
		i++;
	}
	return (i);
}

/*int	main()
{
	int *tab = 0;
	int i = 0;

	i = ft_ultimate_range(&tab, 5, 20);
	if (tab == NULL)
		return (0);
	printf("%d\n", i);
	return (0);
}*/
/*
int	main(int argc, char **argv)
{
	int i = 0;
	int *range;

	ft_ultimate_range(&range, atoi(argv[1]), atoi(argv[2]));
	if (argc > 2)
	{
		while (i + atoi(argv[1]) < atoi(argv[2]))
		{
			printf("%d\n", range[i]);
			i++;
		}
		printf("%d\n", ft_ultimate_range(&range, atoi(argv[1]), atoi(argv[2])));
	}
	return (0);
}*/
