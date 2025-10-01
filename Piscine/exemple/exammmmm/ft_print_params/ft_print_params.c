/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:30:51 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/04 12:01:27 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(c)
{
		write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int i;
	int j;

	i = 5;
	while (i < argc)
	{
		j = 1;
		while (argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}


}
