/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:47:43 by pde-vara          #+#    #+#             */
/*   Updated: 2024/09/30 12:43:58 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (i == n)
		return (0);
	while ((s1[i] || s2[i]) && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main()
{
	char	str1[] = "VBNrmld*gm;*S";
	char	str2[] = "VBNrmld&gm;*S";
	printf("%d\n", ft_strncmp(str1, str2, 8));
	printf("%d", strncmp(str1, str2, 8));

}*/
