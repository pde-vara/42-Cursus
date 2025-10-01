/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:25:02 by pde-vara          #+#    #+#             */
/*   Updated: 2025/02/19 11:22:38 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **src, t_list **dest)
{
	t_list	*temp;

	if (!src || !*src)
		return (-1);
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
	return (0);
}

int	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (-1);
	first = stack[0];
	stack[0] = first->next;
	first->next = NULL;
	last = stack[0];
	while (last->next)
		last = last->next;
	last->next = first;
	return (0);
}

int	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_printf("ra\n");
	return (0);
}
