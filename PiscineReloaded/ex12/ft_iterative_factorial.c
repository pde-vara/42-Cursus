/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:20:33 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/05 12:33:38 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fac;

	fac = nb;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	if (fac != 1)
	{
		fac = fac * (nb - 1);
		nb--;
	}
	return (fac);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ft_iterative_factorial(atoi(argv[1])));
}*/
