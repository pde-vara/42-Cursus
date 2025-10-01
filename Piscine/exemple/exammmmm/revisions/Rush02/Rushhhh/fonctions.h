/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalheir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:17:35 by lmalheir          #+#    #+#             */
/*   Updated: 2024/10/06 15:39:49 by lmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONCTIONS_H
# define FONCTIONS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dictionary
{
	char	*key;
	char	*value;
}t_dict;

void ft_putstr(char *str);
int ft_strlen(char *str);
char **ft_split(char *str, char *charset);

#endif
