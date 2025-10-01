/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:18:46 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/08 15:08:22 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char let)
{
	write(1, &let, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	(void)argc;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
