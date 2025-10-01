/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:43:45 by pde-vara          #+#    #+#             */
/*   Updated: 2024/09/18 20:43:50 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	lettre;

	lettre = 'a';
	while (lettre <= 'z')
	{
		write(1, &lettre, 1);
		lettre ++;
	}
}

/*int main ()
{
	ft_print_alphabet();
}*/
