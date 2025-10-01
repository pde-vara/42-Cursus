/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:43:01 by pde-vara          #+#    #+#             */
/*   Updated: 2024/09/26 15:06:39 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int     main(void)
{
        char source[] = "Bon@ jou$$r";
        char dest[]= "df";
        ft_strcpy(dest, source);
        printf("dest : %s, src: %s\n", dest, source);
        return 0;
}*/
