/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:14:57 by ogoman            #+#    #+#             */
/*   Updated: 2024/01/15 13:24:15 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>
# include "../checker_bonus/checker.h"

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;	

//*** Handle input ./push_swap "1 -42 1337" ***
char			**ft_split(char *str, char separator);

//*** Handle errors-free ***
void			free_matrix(char **argv);
void			error_free(t_stack_node **a, char **argv, bool flag_argc_2);
void			free_stack(t_stack_node **stack);
int				error_repetition(t_stack_node *a, int nbr);
int				error_syntax(char *str_nbr);

//*** Stack creation ***
void			stack_init(t_stack_node **a, char **argv, bool flag_argc_2);
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			set_current_position(t_stack_node *stack);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);

//*** linked list utils ***
void			append_node(t_stack_node **stack, int nbr);
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
void			finish_rotation(t_stack_node **s, t_stack_node *n, char c);

//*** Algorithms ***
void			tiny_sort(t_stack_node **a);
void			handle_five(t_stack_node **a, t_stack_node **b);
void			push_swap(t_stack_node **a, t_stack_node **b);

//*** Commands ***
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);

#endif

// #include <stdlib.h>: Includes the C standard library
// for memory operations (functions like malloc, free, etc.).

// #include <limits.h>: Includes the C standard library for
// working with limits of data types (e.g., INT_MAX, INT_MIN).

// #include <stdbool.h>: Includes the C99 standard library
// for working with boolean types (bool, true, false).

// #include <unistd.h>: Includes the C standard library for
// input/output functions, such as write and read.

// #include <stddef.h>: Includes the C standard library for
// defining standard types and macros, like NULL and size_t.
