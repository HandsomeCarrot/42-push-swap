/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:07:35 by vpoka             #+#    #+#             */
/*   Updated: 2025/01/27 18:52:09 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the next minimum value in the linked list
 * that is greater than the current minimum.
 *
 * This function iterates through the linked list to find
 * the smallest value that is greater than the provided current minimum value.
 * It updates the next minimum value accordingly.
 *
 * @param lst The linked list to search through.
 * @param current_min The current minimum value to compare against.
 * @param next_min The next minimum value found that is
 * greater than the current minimum.
 * @return The next minimum value found in the list that is
 * greater than the current minimum.
 */
static int	get_next_min(t_list *lst, int current_min, int next_min)
{
	while (lst)
	{
		if (*(int *)(lst->content) > current_min
			&& *(int *)(lst->content) < next_min)
			next_min = *(int *)(lst->content);
		lst = lst->next;
	}
	return (next_min);
}

/**
 * @brief Normalizes the values in a linked list.
 *
 * This function takes a linked list and its size, and normalizes the values
 * within the list. The range for the normalization is from
 * [-(size/2), size - (size/2)]
 *
 * @param lst A pointer to the top of the linked list to be normalized.
 * @param size The number of elements in the linked list.
 */
int	normalize_stack(t_list *lst, unsigned int size)
{
	int				min;
	int				max;
	int				normalized;
	t_list			*current_node;

	lst_min_max(lst, &min, &max, 0);
	normalized = -(size / 2);
	while (normalized < (int)(size - (size / 2)))
	{
		current_node = lst;
		while (current_node && get_content(current_node, 0) != min)
			current_node = current_node->next;
		if (!current_node)
			return (0);
		set_content(current_node, normalized, 1);
		min = get_next_min(lst, min, max);
		normalized++;
	}
	return (1);
}
