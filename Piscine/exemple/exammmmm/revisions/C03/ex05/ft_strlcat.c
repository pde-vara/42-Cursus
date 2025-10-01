/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:50:06 by pde-vara          #+#    #+#             */
/*   Updated: 2024/09/30 20:32:37 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	j = ft_strlen(dest);
	len = j;
	if (len >= size)
		return (size + ft_strlen(src));
	else
		len += ft_strlen(src);

	if (size > 0)
	{
		while (src[i] != '\0' && j < (size - 1))
		{
			dest [j] = src [i];
			i++;
			j++;
		}
		dest[j++] != '\0';
	}
	return (len);
}


int main()
{
	char str1[] = "Je veux123456";
	char str2[] = "ma nger";

	printf("%u\n", ft_strlcat(str1, str2, 2));
	printf("%d", strlcat(str1, str2, 2));
}
