/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:04:21 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/10 20:19:25 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int is_power_of_two(unsigned int n)
{
	if (n == 0)
		return(0);
	while (n % 2 == 0)
	{
		n = n/2;
	}
	if (n == 1)
		return(1);
	else 
		return(0);
}

int main(int ac, char **av)
{
	(void)ac;
	printf("%d", is_power_of_two(atoi(av[1])));
}
