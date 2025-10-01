/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:12:09 by pde-vara          #+#    #+#             */
/*   Updated: 2024/09/18 19:31:44 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int	lettre;

	lettre = 'z';
	while (lettre >= 'a')
	{
		write(1, &lettre, 1);
		lettre --;
	}
}

/*int	main(void)
{
	ft_print_reverse_alphabet();
}*/
