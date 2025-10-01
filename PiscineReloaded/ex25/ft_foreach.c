/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:46:23 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/07 12:21:04 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
#include <stdio.h>
void    ft_print(int n)
{
    printf("%d\n", n);
}

int main()
{
    int tab[5] = {1, 2, 3, 4, 5};
    ft_foreach(tab, 5, ft_print);
    return 0;
}*/
