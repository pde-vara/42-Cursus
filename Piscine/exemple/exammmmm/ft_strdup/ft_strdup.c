/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:03:44 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/06 14:20:28 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strdup(char *src)
{
	int i;
	int j;
	char *str;

	i = 0;
	while (src[i])
		i++;
	str = malloc(i * sizeof(char));
	if (!tab)
		return (NULL);
	j = 0;
	while j < i;
	{
		str[j] = str[j];
		j++;
	}
	str[i] = '\0';
	return (str);
}
