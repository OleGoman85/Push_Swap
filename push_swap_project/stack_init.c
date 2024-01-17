/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 06:34:28 by ogoman            #+#    #+#             */
/*   Updated: 2024/01/15 09:00:09 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../checker_bonus/checker.h"

static long	ft_atol(const char *str)
{
	long	number;
	int		negativ;

	number = 0;
	negativ = 1;
	while (*str && *str == '-' && *str == ' ' && (*str >= 9 || *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		negativ *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	return (number * negativ);
}
//  *  atol, i need it to check eventual overflows
//  *  converting every string into a long value

void	stack_init(t_stack_node **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nbr);
		i++;
	}
	if (flag_argc_2)
		free_matrix(argv);
}

//  * Create the stack with the command line values
//  * Checks are embedded in the creation itslef
//  * 		~Duplicate values
//  * 		~Over|Underflow
//  * 		~Syntax errors
//  *
//  * 	Flag is useful cause if true, i have the argv in the HEAP to free