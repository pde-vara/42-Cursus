/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:04:01 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/10 11:50:37 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>


void putchar(char nb)
{
	write(1, &nb, 1);
}


void w_nb(int nb)
{
	if (nb > 9)
	{
		w_nb(nb / 10);
	}
	putchar((nb % 10) + '0');
}

void putstring(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}

}

int main()
{
	int nb;
	nb = 1;
	while (nb <= 100)
	{
		if (nb % 3 == 0 && nb % 5 == 0)
			putstring("fizzbuzz");
		else if (nb % 3 == 0)
			putstring("fizz");
		else if (nb % 5 == 0)
                        putstring("buzz");
		else 
			w_nb(nb);
		nb++;
		write(1, "\n", 1);
	}
}
