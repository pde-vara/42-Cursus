/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:42:57 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/11 17:57:54 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_display_error(char *str_error)
{
	write(2, str_error, ft_strlen(str_error));
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	int		fd;
	int		bytes_read;
	char	tab[10000];

	if (ac < 2)
		ft_display_error("file name missing");
	else if (ac > 2)
		ft_display_error("Too many arguments.");
	if (ac != 2)
		return (1);
	fd = open (av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_display_error("Cannot read file.");
		return (1);
	}
	bytes_read = read(fd, tab, sizeof(tab));
	while (bytes_read > 0)
	{
		write(1, tab, bytes_read);
		bytes_read = read(fd, tab, sizeof(tab));
	}
	close(fd);
	return (0);
}
/*
Step1: Variables fd file descriptor, byteread bytescounter, 
tab[10000] tab static with big size.
Step2: Test of arguments if missing or too much.
Step3: File opening and reading.
Step4: Test if error file opening.
Step5: Reading and display file as size tab.
step6: File closing*/
