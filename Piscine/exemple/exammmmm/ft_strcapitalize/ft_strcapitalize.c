/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:06:39 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/04 13:31:10 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

char *ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\0')
	{
		return (str);
	}
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') 
				&& (str[i - 1] == ' ' || str[i - 1] == '-' || str[i - 1] == '+'))
		{
			str[i] -= 32;
/*			write(1, &str[i], 1);
		}
		else
		{
			write(1, &str[i], 1);*/
		}
		i++;
	}
	return(str);
}
/*
int main(int argc, char **argv)
{
	(void)argc;
	ft_strcapitalize(argv[1]);
}
*/
int     main(void)
{
	char a[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s",ft_strcapitalize(a));
	return(0);
}
