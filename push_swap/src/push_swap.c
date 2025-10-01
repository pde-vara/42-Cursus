/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:10:32 by pde-vara          #+#    #+#             */
/*   Updated: 2025/02/14 18:24:25 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*next;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*stack = NULL;
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	set_stacks(t_list ***stack_a, t_list ***stack_b)
{
	*stack_a = (t_list **)malloc(sizeof(t_list *));
	if (!*stack_a)
		return (0);
	*stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!*stack_b)
	{
		free(*stack_a);
		return (0);
	}
	**stack_a = NULL;
	**stack_b = NULL;
	return (1);
}

void	cleanup_stacks(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
	{
		free_stack(stack_a);
		free(stack_a);
	}
	if (stack_b)
	{
		free_stack(stack_b);
		free(stack_b);
	}
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 2)
		return (-1);
	parse_arg(ac, av);
	if (!set_stacks(&stack_a, &stack_b))
		return (ft_error("Malloc error", NULL, 0), -1);
	init_stack(stack_a, ac, av);
	if (is_sorted(*stack_a))
		return (cleanup_stacks(stack_a, stack_b), 0);
	if (ft_lstsize(*stack_a) <= 5)
		sort_small_stack(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	cleanup_stacks(stack_a, stack_b);
	return (0);
}
