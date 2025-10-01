/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:21:38 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/08 20:29:11 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char let)
{
	write(1, &let, 1);
}

void	ft_putnbr(int nb)
{
//	int	diz;
//	int	mod;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	if (nb >  9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);	
}

int	main(void)
{
	ft_putnbr(0);
		ft_putchar('\n');
	ft_putnbr(-2147483648);
		ft_putchar('\n');
	ft_putnbr(2147483647);
		ft_putchar('\n');
	ft_putnbr(56 * 4);
		ft_putchar('\n');
	ft_putnbr(1000);
		ft_putchar('\n');
	ft_putnbr(-345678);
	return (0);
}


/*
fct 12345
	fct 1234
		fct 123
			fct 12
				fct 1*/
