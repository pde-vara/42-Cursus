/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:12:51 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/09 15:18:15 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_print_alphabet(void)
{
	char let;
	let = 'a';
	while (let <= 'z')
	{
		write(1, &let, 1);
		let++;
	}
}

int main()
{
	ft_print_alphabet();
}
