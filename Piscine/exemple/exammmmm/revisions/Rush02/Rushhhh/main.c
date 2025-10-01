/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:12:50 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/06 13:40:27 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "fonctions.h"

int main(int argc, char **argv)
{
	int fd;
	
	if (argc > 3 || argc == 1)
	{
		write(1, "error", 5);
		return (0);
	}
	if ((argc == 3 && argv[2] < 0) || (argc == 2 && argv[1] < 0))
	{
		write(1, "error", 5);
		return (0);
	}
	
	fd = open("/mnt/nfs/homes/pde-vara/Downloads/numbers.dict", O_RDONLY);
	if (fd == -1) 
	{
		write(1, "Dict Error\n", 11);
		return NULL;
	}
	close(fd);
	return (0);
}
void	ft_putnbr(int nb)
	if (num >= 100)
	if (num >= 20)
	if (nb >= 9)
		ft_putnbr(nb / 10);
	else
	{
		ft_putchar(nb + '0');
	}	
