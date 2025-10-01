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

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int len;

    len = ft_strlen(dest);
    
    if (size <= len)
        return (size + ft_strlen(src));

    while (src[i] != '\0' && (len + i) < (size - 1)) 
    {
        dest[len + i] = src[i];
        i++;
    }
    
    dest[len + i] = '\0';
    
    return (len + ft_strlen(src));
}
```


int main()
{
	char str1[] = "Je veux123456";
	char str2[] = "ma nger";

	printf("%u\n", ft_strlcat(str1, str2, 2));
	printf("%d", strlcat(str1, str2, 2));
}








#### Explication des changements :
1. J'ai modifié la gestion de `size` pour retourner la somme correcte des longueurs de `dest` et `src` si `size` est trop petit.
2. Le contrôle `while (len + i) < (size - 1)` est utilisé pour s'assurer qu'on ne dépasse pas la taille du tampon `dest`, tout en laissant la place pour le `\0`.

