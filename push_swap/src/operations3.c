/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:26:28 by pde-vara          #+#    #+#             */
/*   Updated: 2025/02/19 11:22:48 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_printf("rb\n");
	return (0);
}

int	reverse_rotate(t_list **stack)
{
	t_list	*antepenultieme;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (-1);
	antepenultieme = NULL;
	last = *stack;
	while (last->next)
	{
		antepenultieme = last;
		last = last->next;
	}
	antepenultieme->next = NULL;
	last->next = *stack;
	*stack = last;
	return (0);
}

int	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
	return (0);
}
