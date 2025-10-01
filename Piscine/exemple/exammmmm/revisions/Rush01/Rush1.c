/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:00:20 by pde-vara          #+#    #+#             */
/*   Updated: 2024/09/28 18:02:17 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_grille(int grid[4][4])
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j];
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	ft_vuedelagauche(int *ligne, int demande)
{
	int	hmax;
	int	nbvisible;
	int	i;

	hmax = 0;
	nbvisible = 0;
	i = 0;
	while (i < 4)
	{
		if (ligne[i] > hmax)
		{
			hmax = ligne[i];
			nbvisible++;
		}
		i++;
	}
	return (nbvisible);
}

int	ft_vuedeladroite(int *ligne, int demande)
{
	int	hmax;
	int	nbvisible;
	int	i;

	hmax = 0;
	nbvisible = 0;
	i = 3;
	while (i >= 0)
	{
		if (ligne[i] > hmax)
		{
			hmax = ligne[i];
			nbvisible++;
		}
		i--;
	}
	return (nbvisible);
}
