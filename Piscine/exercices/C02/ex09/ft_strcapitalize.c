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

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	majuscule0(char *str)
{
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] -= 32;
	}
	return (*str);
}

char	*fr_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (str);
	}
	ft_strlowcase(str);
	majuscule0(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			if (!(str[i - 1] >= 'a' && str[i - 1] <= 'z'))
				if (!(str[i - 1] >= '1' && str[i - 1] <= '9'))
					if (!(str[i - 1] >= 'A' && str[i - 1] <= 'Z'))
						str[i] -= 32;
					i++;
	}
	return (str);
}

/*int     main(void)
{
	char a[] = "salut, comment tu vas ? 42mots que-deux; cinquaUY.yfghjj YRJKghj";
	printf("%s",fr_strcapitalize(a));
	return(0);
}*/
