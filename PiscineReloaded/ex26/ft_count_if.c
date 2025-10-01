/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:22:00 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/11 18:07:05 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	cpt;

	cpt = 0;
	while (*tab != 0)
	{
		if (f(*tab))
			cpt++;
		tab++;
	}
	return (cpt);
}
/*
int test(char *str)
{
    return (str[0] == 'o');
}

#include <stdio.h>
int main(void)
{
    char    *tab[3] = {"oui", "non", 0};
    printf("%d\n", ft_count_if(tab, test));
    return 0;
}*/
