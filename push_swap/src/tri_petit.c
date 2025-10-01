/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_petit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:45:01 by pde-vara          #+#    #+#             */
/*   Updated: 2025/02/14 18:19:49 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		rra(stack);
		sa(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

int	find_min_index(t_list *stack)
{
	int		min;
	int		index;
	t_list	*tmp;

	min = stack->value;
	index = stack->index;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}

void	sort_four_five(t_list **stack_a, t_list **stack_b)
{
	int	min_idx;

	while (ft_lstsize(*stack_a) > 3)
	{
		min_idx = find_min_index(*stack_a);
		while ((*stack_a)->index != min_idx)
		{
			if (min_idx < ft_lstsize(*stack_a) / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		if (is_sorted(*stack_a))
			break ;
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
}

int	sort_small_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize((*stack_a));
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4 || size == 5)
		sort_four_five(stack_a, stack_b);
	return (0);
}
