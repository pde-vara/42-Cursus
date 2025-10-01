/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:49:49 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/10 17:02:39 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void ft_swap(char **s1, char **s2)
{
	char *temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}


int main(int ac, char **av)
{
	int i;
	int j;
	int k;
	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (ft_strcmp(av[i], av[j]) > 0 && j < ac)
		{
			ft_swap(&av[i], &av[j]);
		       	j++;
		}
		i++;
	}
	k = 0;
	while (k < ac)
	{
		ft_putstr(av[k]);
		k++;
	}
	return(0);
}
