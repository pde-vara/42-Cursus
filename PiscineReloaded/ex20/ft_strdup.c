/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:18:50 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/05 18:26:28 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	while (src[j])
		j++;
	str = malloc(j * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < j)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_strdup(argv[1]));
}*/
