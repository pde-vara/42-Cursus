/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:53:17 by pde-vara          #+#    #+#             */
/*   Updated: 2025/02/19 14:11:11 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

// push_swap.c

int		ft_lstsize(t_list *stack);
void	ft_error(char *msg, char **args, int argc);
int		ft_doublons(int num, char **args, int i);
int		ft_isnum(char *num);
void	parse_arg(int argc, char **argv);
t_list	*create_node(int value, int i);
void	add_to_stack(t_list **stack_a, t_list *new);
void	init_stack(t_list **stack_a, int ac, char **av);
void	free_stack(t_list **stack);
void	free_args(char **args);

// operations.c
int		swap(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		push(t_list **src, t_list **dest);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		rotate(t_list **stack);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		reverse_rotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

// Petit tri
int		find_min_index(t_list *stack);
void	sort_two(t_list **stack);
void	sort_three(t_list **stack);
void	sort_four_five(t_list **stack_a, t_list **stack_b);
int		sort_small_stack(t_list **stack_a, t_list **stack_b);

// radix_sort.c
int		is_sorted(t_list *stack);
void	assign_index(t_list *stack);
int		ft_max_bits(t_list *stack);
void	radix_sort(t_list **stack_a, t_list **stack_b);

#endif