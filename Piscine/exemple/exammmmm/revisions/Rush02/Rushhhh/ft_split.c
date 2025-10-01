/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalheir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:14:37 by lmalheir          #+#    #+#             */
/*   Updated: 2024/10/06 15:14:41 by lmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonctions.h"

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_charset(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_in_charset(str[i], charset))
		i++;
	return (i);
}

int	count(char *str, char *charset)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (str[i])
	{
		while (str[i] && is_in_charset(str[i], charset))
			i++;
		if (str[i])
			wordcount++;
		while (str[i] && !is_in_charset(str[i], charset))
			i++;
	}
	return (wordcount);
}

char	*cut_string(char *str, char *charset)
{
	int		len;
	char	*result;
	int		i;

	i = 0;
	len = ft_strlen_charset(str, charset);
	result = malloc(len + 1);
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**tab;

	i = 0;
	tab = (char **) malloc(sizeof(char *) * (count(str, charset) + 1));
	while (*str)
	{
		while (*str && is_in_charset(*str, charset))
			str++;
		if (*str)
		{
			tab[i] = cut_string(str, charset);
			i++;
		}
		while (*str && !is_in_charset(*str, charset))
			str++;
	}
	tab[i] = 0;
	return (tab);
}
