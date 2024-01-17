/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:29:41 by utente            #+#    #+#             */
/*   Updated: 2024/01/12 15:11:45 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 4
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include "../push_swap_project/push_swap.h"

/*
 * Linked list for get next line
*/
typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}				t_list;

//*** Get next line utlis ***
int				found_newline(t_list *list);
t_list			*find_last_node_2(t_list *list);
char			*get_line(t_list *list);
void			copy_str(t_list *list, char *str);
int				len_to_newline(t_list *list);
void			polish_list(t_list **list);
char			*get_next_line(int fd);
void			dealloc(t_list **list, t_list *clean_node, char *buf);
void			create_list(t_list **list, int fd);

#endif
