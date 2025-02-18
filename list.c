/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:05:33 by vpoka             #+#    #+#             */
/*   Updated: 2025/02/18 15:25:48 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Skips whitespace characters in a string
 * 
 * @param str_pos Starting index in the string
 * @param str Input string to process
 * @return int New position after skipping whitespace
 * 
 * Skips spaces, tabs, and other whitespace characters as defined by isspace(3).
 * Handles all standard whitespace: ' ', \t, \n, \v, \f, \r
 */
static int	skip_space(int str_pos, char *str)
{
	int	pos;

	pos = str_pos;
	while (str[pos] == ' ' || str[pos] == '\t' || str[pos] == '\n'
		|| str[pos] == '\v' || str[pos] == '\f' || str[pos] == '\r')
		pos++;
	return (pos);
}

/**
 * @brief Advances past numeric characters and optional sign
 * 
 * @param str Input string containing numbers
 * @param str_pos Starting position in the string
 * @return int New position after skipping all numeric characters
 * 
 * Processes optional '+' or '-' sign followed by digits.
 * Used to move past complete number representations in strings.
 */
static int	skip_nums(char *str, int str_pos)
{
	if (str[str_pos] == '+' || str[str_pos] == '-')
		str_pos++;
	while (ft_isdigit(str[str_pos]))
		str_pos++;
	return (str_pos);
}

/**
 * @brief Validates if string represents a true zero value
 * 
 * @param str_pos Starting position in the string
 * @param str Input string to check
 * @return int 1 if valid zero (with optional sign), 0 otherwise
 * 
 * Checks for optional sign followed by only zero digits.
 * Prevents invalid zeros like "00012" or "+000a".
 */
static int	is_num_0(int str_pos, char *str)
{
	if (str[str_pos] == '+' || str[str_pos] == '-')
		str_pos++;
	if (!ft_isdigit(str[str_pos]))
		return (0);
	while (ft_isdigit(str[str_pos]))
	{
		if (str[str_pos] != '0')
			return (0);
		str_pos++;
	}
	return (1);
}

/**
 * @brief Creates new list node with validated number
 * 
 * @param str Input string containing number
 * @param str_pos Starting position in the string
 * @return t_list* New node or NULL on failure
 * 
 * Converts substring to integer using ft_atoi.
 * Validates number format with is_num_0 for zero values.
 * Cleans up memory and returns NULL on any allocation failure.
 */
t_list	*create_new_node(char *str, int str_pos)
{
	int		*number;
	t_list	*new_node;

	number = malloc(sizeof(int) * 2);
	if (!number)
		return (NULL);
	number[0] = ft_atoi(str + str_pos);
	number[1] = 0;
	if (number[0] == 0 && !is_num_0(str_pos, str))
		return (free(number), NULL);
	new_node = ft_lstnew(number);
	if (!new_node)
		return (free(number), NULL);
	return (new_node);
}

/**
 * @brief Creates and initializes a linked list from command line arguments
 * 
 * @param ac Argument count from main
 * @param av Array of string arguments from main
 * @param empty Pointer to flag indicating if list is empty
 * (1=empty, 0=not empty)
 * @return t_list* Pointer to first node of created list, NULL if:
 *                 - Memory allocation fails
 *                 - Invalid number format detected
 *                 - Empty input (no numbers)
 * 
 * Detailed behavior:
 * 1. Processes each argument string sequentially
 * 2. Handles multiple numbers within single argument (space-separated)
 * 3. Skips whitespace (spaces, tabs, newlines)
 * 4. Validates number format:
 *    - Optional +/- sign
 *    - Only digits after sign
 *    - Within integer range
 * 5. Creates nodes with two integers per node:
 *    - Original value at index 0
 *    - Normalized value at index 1 (initially 0)
 * 6. Updates empty flag to 0 when first valid number is added
 * 
 * Memory management:
 * - Frees all allocated memory on any error
 * - Uses ft_lstnew for node creation
 * - Uses ft_lstadd_back for list construction
 */
t_list	*create_list(int ac, char **av)
{
	t_list	*top;
	t_list	*new_node;
	int		arg;
	int		str_pos;

	arg = 1;
	top = NULL;
	while (ac && arg < ac && av && av[arg])
	{
		str_pos = skip_space(0, av[arg]);
		while (av && av[arg] && av[arg][str_pos])
		{
			new_node = create_new_node(av[arg], str_pos);
			if (!new_node)
				return (ft_lstclear(&top, &free), NULL);
			ft_lstadd_back(&top, new_node);
			str_pos = skip_nums(av[arg], str_pos);
			str_pos = skip_space(str_pos, av[arg]);
		}
		arg++;
	}
	return (top);
}
