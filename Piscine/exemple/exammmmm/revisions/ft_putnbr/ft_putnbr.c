
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:21:57 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/08 17:45:55 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char n)
{
	write(1, &n, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');

}
/*
int main(int argc, char **argv)
{
	(void)argc;
	ft_putnbr(atoi(argv[1]));
}
*/
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
	ft_putnbr(-3456);
	return (0);
}

3456
	345
		34
			3
