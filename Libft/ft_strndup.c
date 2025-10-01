/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:37:44 by pde-vara          #+#    #+#             */
/*   Updated: 2025/03/19 15:41:06 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <bsd/string.h>

char	*ft_strndup(const char *s, ssize_t n)
{
	ssize_t		i;
	char	*str;

	i = 0;
	while (s[i] && i < n)
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_strndup(argv[1]));
	printf("%s\n", strnup(argv[1]));
}
*/