/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:12:50 by pde-vara          #+#    #+#             */
/*   Updated: 2024/10/06 13:40:27 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "fonctions.h"

int main(int argc, char **argv)
{
	int fd;
	
	if (argc > 3 || argc == 1)
	{
		write(1, "error", 5);
		return (0);
	}
	if ((argc == 3 && argv[2] < 0) || (argc == 2 && argv[1] < 0))
	{
		write(1, "error", 5);
		return (0);
	}
	
	fd = open("./rush-02", O_RDONLY, );
	write(fd, &c, 1);
	close(fd);
	return (0);
}


si 2 param, argv[1] est ce qu'on recherche
si 3 le premier est le chemin vers le dict
ouvrir numberc. dict avec open,
le resultat stocker dans fonct fd

