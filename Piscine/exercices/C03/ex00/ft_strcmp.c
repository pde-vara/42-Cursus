/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:08:37 by pde-vara          #+#    #+#             */
/*   Updated: 2024/09/26 21:47:09 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
			i++;
	}
	return (s1[i] - s2[i]);
}

int main()
{
	char str1[] = "elias";
	char str2[] = "eliat";
	printf("%d", ft_strcmp(str1, str2));
	printf("%d", strcmp(str1, str2));

}
