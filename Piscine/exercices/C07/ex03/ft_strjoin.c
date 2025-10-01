/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:39:28 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/09 17:21:50 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;
	int	j;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			total_len++;
		}
		i++;
	}
	total_len = total_len + (ft_strlen(sep) * (size - 1));
	return (total_len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_len;
	char	*str;

	total_len = ft_total_len(size, strs, sep);
	if (size == 0)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str = malloc(total_len * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		ft_strcat(str, strs[i]);
		ft_strcat(str, sep);
		i++;
	}
	ft_strcat(str, strs[i]);
	str[ft_strlen(str)] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*sep;
	char	*strs[] = {"Bonjour", "des", "vacances"};
	int	s;
	char	*tab;

	sep = "==";
	s = 3;
	tab = ft_strjoin(s, strs, sep);
	printf("%s\n", tab);
	return (0);
}*/
