/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:26:44 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/10 21:15:48 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>



void rot(char *let)
{
	int i = 0;
	while (let[i])
	{
		if ((let[i] >= 'a' && let[i] <= 'm') || (let[i] >= 'A' && let[i] <= 'M'))
		{
			let[i] += 13;
			write(1, &let[i], 1);
			i++;
		}
		else if ((let[i] >= 'm' && let[i] <= 'z') || (let[i] >= 'M' && let[i] <= 'Z'))
		{
			let[i] -= 13;
	                write(1, &let[i], 1);
	                i++;
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return(0);
	rot(av[1]);
}
