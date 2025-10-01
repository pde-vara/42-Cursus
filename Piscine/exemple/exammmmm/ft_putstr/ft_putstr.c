/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:58:23 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/04 14:10:59 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_putchar(c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int main()
{
	char s1[] = "RTYUIOOIJfgbnkyhj";
	ft_putstr(s1);
}
