/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:01:43 by vpoka             #+#    #+#             */
/*   Updated: 2025/02/18 17:02:44 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Main entry point for push_swap program
 * 
 * @param ac Argument count
 * @param av Argument vector (array of strings)
 * @return int Returns 1 on success, 0 on error
 *
 * Handles input validation, stack initialization, sorting and cleanup.
 * Prints "Error\n" to stderr if input is invalid.
 */
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*list_top;

	if (ac == 1)
		return (0);
	list_top = create_list(ac, av);
	if (!list_top)
		return (write(2, "Error\n", sizeof(char) * 6), 1);
	a = new_stack(list_top);
	b = new_stack(NULL);
	if (!a || !b || list_has_duplicates(a->top))
	{
		free_stacks(a, b, &list_top);
		write(2, "Error\n", sizeof(char) * 6);
		return (1);
	}
	if (!lst_sorted(a->top))
		sort_stack(a, b);
	free_stacks(a, b, &list_top);
	return (0);
}
