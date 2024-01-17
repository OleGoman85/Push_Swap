/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:56:44 by ogoman            #+#    #+#             */
/*   Updated: 2024/01/15 09:02:32 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../checker_bonus/checker.h"

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

//  * Args at the command line are
//  * spaced separated strings

static char	*get_next_word(char *str, char sep)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == sep)
		++cursor;
	while ((str[cursor + len] != sep) && str[cursor + len])
		len++;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (next_str == NULL)
		return (NULL);
	while ((str[cursor] != sep) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}
//  * I exploit static variables
//  * which are basically 
//  * "Global private variables"
//  * i can access it only via the get_next_word function

char	**ft_split(char *str, char sep)
{
	int			i;
	int			words_number;
	char		**array_of_strings;

	i = 0;
	words_number = count_words(str, sep);
	if (!words_number)
		exit(1);
	array_of_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (array_of_strings == NULL)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (i == 0)
		{
			array_of_strings[i] = malloc(sizeof(char));
			if (array_of_strings[i] == NULL)
				return (NULL);
			array_of_strings[i++][0] = '\0';
			continue ;
		}
		array_of_strings[i++] = get_next_word(str, sep);
	}
	array_of_strings[i] = NULL;
	return (array_of_strings);
}

//  * I recreate an argv in the HEAP
//  *
//  * +2 because i want to allocate space
//  * for the "\0" Placeholder and the final NULL
//  *
//  * vector_strings-->[p0]-> "\0" Placeholder to mimic argv
//  * 				 |->[p1]->"Hello"
//  * 				 |->[p2]->"how"
//  * 				 |->[p3]->"Are"
//  * 				 |->[..]->"..""
//  * 				 |->[NULL]