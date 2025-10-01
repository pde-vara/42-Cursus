/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:25:19 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/05 10:42:53 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char	nb;

	nb = '0';
	while (nb <= '9')
	{
		ft_putchar(nb);
		nb++;
	}
}
/*
int main()
{
	ft_print_numbers();
}*/
