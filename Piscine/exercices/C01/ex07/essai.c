/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essai.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:49:55 by pde-vara          #+#    #+#             */
/*   Updated: 2024/09/24 19:49:59 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int a;
	a = 0;
	int z;
	z = size -1;
	int temp;
	while (a <= z)
	{
		temp = tab[a];
		tab[a] = tab[size -1];
		tab[size -1] = temp;
		a++;
		z--;
	}
}

int main ()
{ 
	int i = 9;
	int tab[] = {1,2,3,4,5,6,7,8,9};
	ft_rev_int_tab(tab, i);
	printf("%d", *tab);
}
