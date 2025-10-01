/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:11:36 by pde-vara          #+#    #+#             */
/*   Updated: 2025/02/14 18:19:20 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int value, int i)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (ft_printf("Malloc error"), NULL);
	new->value = value;
	new->index = i;
	new->next = NULL;
	return (new);
}

void	add_to_stack(t_list **stack_a, t_list *new)
{
	t_list	*temp;

	if (!*stack_a)
	{
		*stack_a = new;
		return ;
	}
	temp = *stack_a;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	init_stack(t_list **stack_a, int ac, char **av)
{
	char	**args;
	int		i;
	t_list	*new;

	i = 0;
	if (!stack_a)
		return (ft_error("Error\n", NULL, 0));
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		new = create_node(ft_atoi(args[i]), i - 1);
		add_to_stack(stack_a, new);
		i++;
	}
	if (ac == 2)
		free_args(args);
}
