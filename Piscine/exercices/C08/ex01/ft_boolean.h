/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:45:46 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/08 21:39:06 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	FT_BOOLEAN_H
#define	FT_BOOLEAN_H

# include <unistd.h>

typedef int t_bool;
# define EVEN(nb) (nb % 2) == 0? 1 :0

# define TRUE 1

# define FALSE 0

# define EVEN_MSG "I have an even number of arguments."

# define ODD_MSG "I have an odd number of arguments.\n"

# define SUCCESS 0
#endif
