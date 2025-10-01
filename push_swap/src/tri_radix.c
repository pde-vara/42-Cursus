/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_radix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:44:55 by pde-vara          #+#    #+#             */
/*   Updated: 2025/02/14 18:23:49 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	assign_index(t_list *stack)
{
	t_list	*current;
	t_list	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	ft_max_bits(t_list *stack)
{
	t_list	*temp;
	int		max;
	int		max_bits;

	if (!stack)
		return (ft_error("Error\n", NULL, 0), 0);
	temp = stack;
	max_bits = 0;
	max = stack->index;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		max_bits;
	int		size;

	size = ft_lstsize(*stack_a);
	assign_index(*stack_a);
	max_bits = ft_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
