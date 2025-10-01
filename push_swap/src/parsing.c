/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:23:11 by pde-vara          #+#    #+#             */
/*   Updated: 2025/02/13 10:37:38 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_error(char *msg, char **args, int argc)
{
	ft_putendl_fd(msg, 2);
	if (args && argc == 2)
		free_args(args);
	exit (1);
}

int	ft_doublons(int num, char **args, int index)
{
	int	i;

	i = 0;
	if (!args)
		return (0);
	while (i < index)
	{
		if (ft_atoi(args[i]) == ((ssize_t)num))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (!num)
		return (0);
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	parse_arg(int argc, char **argv)
{
	char	**args;
	int		i;
	long	tmp;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv + 1;
	}
	while (args[i])
	{
		if (!ft_isnum(args[i]))
			ft_error("Error\n", args, argc);
		tmp = ft_atoi(args[i]);
		if (!ft_doublons(tmp, args, i))
			ft_error("Error\n", args, argc);
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error\n", args, argc);
		i++;
	}
	if (argc == 2)
		free_args(args);
}
