/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 10:13:20 by ogoman            #+#    #+#             */
/*   Updated: 2024/01/15 11:30:35 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../checker_bonus/checker.h"

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	center_line;

	i = 0;
	if (stack == NULL)
		return ;
	center_line = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= center_line)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}
//  * Set the current position of every node 
//  * in the current state-configuration

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_in_a;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a ->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_in_a = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_in_a;
		b = b->next;
	}
}
// * Best Matching...
//  *   | "The Smallest Greater Value" |
//  *
//  * If no node in a is greater than the node in b,
// 		the best match will be the smallest node in a.
//  * Briefly
//  * This function ensures that each node in b is matched
// 			as best as possible with a node in a.

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}
// The function sets prices for moving a node from stack b to stack a.
// Prices are determined based on the relative positions of nodes in the stack,
// considering additional conditions like above_median. 
// The goal is to identify the optimal node to move to stack a by evaluating
// the cost of each node in stack b.

// Set the prices to push the node from b -> a
// * PUSH_PRICE = B node position
// * if B above_median FALSE (B length - B node position)
// * if A above_median TRUE (Push_price + A node position)
// * if A above_median FALSE (A length - A node position) 

void	set_cheapest(t_stack_node *b)
{
	long			best_match_value;
	t_stack_node	*best_match_node;

	if (b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

//  * Flag the cheapest node in the current
//  * stacks configurations

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}

//  * All the necessary values to make the push
//  * 		~Relative Positions
//  * 		~Target node, the b node to make emerge
//  * 		~Price for every configuration
//  * 		~Cheapest in the current configuration