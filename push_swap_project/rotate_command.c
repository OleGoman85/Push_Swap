/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:14:41 by ogoman            #+#    #+#             */
/*   Updated: 2024/01/13 10:13:54 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../checker_bonus/checker.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	t_stack_node	*first_node;
	t_stack_node	*second_node;
	int				len;

	len = stack_len(*stack);
	if (*stack == NULL || len < 2)
		return ;
	last_node = find_last_node(*stack);
	first_node = *stack;
	second_node = first_node->next;
	last_node->next = first_node;
	*stack = second_node;
	second_node->prev = NULL;
	last_node->next->prev = last_node;
	first_node->prev = last_node;
	first_node->next = NULL;
}

void	ra(t_stack_node **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}
// Top node to bottom position