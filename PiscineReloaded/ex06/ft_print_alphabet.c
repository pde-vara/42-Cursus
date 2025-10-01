/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:15:32 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/05 10:24:48 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	let;

	let = 'a';
	while (let <= 'z')
	{
		ft_putchar(let);
		let++;
	}
}
/*
int main()
{
	ft_print_alphabet();
}*/
