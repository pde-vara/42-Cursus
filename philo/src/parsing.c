/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:57:33 by pde-vara          #+#    #+#             */
/*   Updated: 2025/03/18 11:47:47 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && i < n && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (!num)
		return (-1);
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

ssize_t	ft_atoi(const char *nptr)
{
	int			i;
	long int	nbfinal;

	i = 0;
	nbfinal = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			return (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbfinal = (nbfinal * 10) + (nptr[i] - '0');
		i++;
	}
	if (nbfinal > 2147483647)
		return (-1);
	return (nbfinal);
}

int	is_valid_input(int ac, char **av)
{
	int	i;
	int	nb;

	i = 1;
	while (i < ac)
	{
		if (ft_isnum(av[i]) != 0)
			return (printf("error non num"), -1);
		if (ft_atoi(av[2]) == 0)
			return (printf("min tps"), -1);
		nb = ft_atoi(av[i]);
		if (i == 1 && (nb <= 0 || nb > 250))
			return (printf("error max philo nb = 250"), -1);
		if (nb < 0)
			return (printf("error int overflow"), -1);
		i++;
	}
	return (0);
}
