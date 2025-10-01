/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:34:35 by pde-vara          #+#    #+#             */
/*   Updated: 2024/09/25 21:50:41 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*fr_strcapitalize(char *str)
{
	int	i;

	i = 0;
/*	if (str[i] == '\0')
	{
		return(str);
	}*/

	while (str[i] != '\0')
	{
		if	(str[i - 1] >= 0 && str[i - 1] <= 97)
		{
			str[i] -= 32;
	//		i++;
		}
		i++;
	}
	return (str);

}

int     main(void)
{
	char a[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s",fr_strcapitalize(a));
	return(0);
}
