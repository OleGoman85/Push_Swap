/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:07:40 by ogoman            #+#    #+#             */
/*   Updated: 2024/01/13 10:14:49 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../checker_bonus/checker.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	t_stack_node	*first_node;
	int				len;

	len = stack_len(*stack);
	if (*stack == NULL || len < 2)
		return ;
	last_node = find_last_node(*stack);
	first_node = *stack;
	first_node->prev = last_node;
	last_node->next = first_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	*stack = last_node;
}

void	rra(t_stack_node **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
//Bottom to top