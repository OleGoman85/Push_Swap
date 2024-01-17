/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:16:24 by ogoman            #+#    #+#             */
/*   Updated: 2024/01/15 09:06:15 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../checker_bonus/checker.h"

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

//  * Search for the last node

void	append_node(t_stack_node **stack, int data)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->value = data;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

//  * append node

t_stack_node	*find_smallest(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;
	t_stack_node	*cur_node;

	cur_node = stack;
	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (cur_node)
	{
		if (cur_node->value < smallest)
		{
			smallest = cur_node->value;
			smallest_node = cur_node;
		}
		cur_node = cur_node->next;
	}
	return (smallest_node);
}

//  * Find the smallest value node

int	stack_len(t_stack_node *stack)
{
	int				count;
	t_stack_node	*cur_node;

	if (stack == NULL)
		return (0);
	cur_node = stack;
	count = 0;
	while (cur_node)
	{
		cur_node = cur_node->next;
		count++;
	}
	return (count);
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	t_stack_node	*cur_node;

	if (stack == NULL)
		return (NULL);
	cur_node = stack;
	while (cur_node)
	{
		if (cur_node->cheapest)
			return (cur_node);
		cur_node = cur_node->next;
	}
	return (NULL);
}

//  * Return the cheapest node 
//  * that is already flagged