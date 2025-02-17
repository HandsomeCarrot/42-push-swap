/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:42:17 by vpoka             #+#    #+#             */
/*   Updated: 2025/01/27 18:43:05 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Gets the content value from a list node
 * 
 * @param node Pointer to the list node
 * @param normalized Flag to get either original (0) or normalized (1) value
 * @return Content value from the node, or 0 if node is NULL
 */
int	get_content(t_list *node, int normalized)
{
	if (node)
		return (((int *)node->content)[normalized]);
	return (0);
}

/**
 * @brief Sets the content value of a list node
 * 
 * @param node Pointer to the list node
 * @param new_cont New value to set
 * @param normalized Flag to set either original (0) or normalized (1) value
 */
void	set_content(t_list *node, int new_cont, int normalized)
{
	if (node)
		((int *)node->content)[normalized] = new_cont;
}

/**
 * Finds the minimum and maximum values in a linked list
 * @param lst Pointer to the first node of the linked list
 * @param min Pointer to store the minimum value (can be NULL)
 * @param max Pointer to store the maximum value (can be NULL)
 */
void	lst_min_max(t_list *lst, int *min, int *max, int normalized)
{
	if (lst)
	{
		if (min)
			*min = get_content(lst, normalized);
		if (max)
			*max = get_content(lst, normalized);
		while (lst)
		{
			if (min && get_content(lst, normalized) < *min)
				*min = get_content(lst, normalized);
			if (max && get_content(lst, normalized) > *max)
				*max = get_content(lst, normalized);
			lst = lst->next;
		}
	}
}

/**
 * Checks if a linked list is sorted in ascending order
 * @param lst Pointer to the first node of the linked list
 * @return 1 if the list is sorted, 0 otherwise
 */
int	lst_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (get_content(lst, 0) > get_content(lst->next, 0))
			return (0);
		lst = lst->next;
	}
	return (1);
}

/**
 * Checks if a list contains duplicate values
 * @param lst Pointer to the list structure
 * @return 1 if duplicates are found, 0 otherwise
 */
int	list_has_duplicates(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (1);
	while (lst)
	{
		current = lst->next;
		while (current)
		{
			if (get_content(lst, 0) == get_content(current, 0))
				return (1);
			current = current->next;
		}
		lst = lst->next;
	}
	return (0);
}
