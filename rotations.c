/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:02:00 by vpoka             #+#    #+#             */
/*   Updated: 2025/01/27 18:52:49 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if the linked list contains an integer within specified bounds
 * @param lst       The linked list to check
 * @param threshold The boundary value to compare against
 * @param smaller   Flag indicating whether to look for values smaller (1)
 * or larger (0) than threshold
 * @return          1 if found a number within bounds, -1 otherwise
 */
static int	has_int_within_bound(t_list *lst, int threshold, int smaller)
{
	while (lst)
	{
		if ((smaller && get_content(lst, 1) < threshold)
			|| (!smaller && get_content(lst, 1) >= threshold))
			return (1);
		lst = lst->next;
	}
	return (-1);
}

/**
 * @brief Counts steps needed to reach next number meeting
 * threshold condition when rotating backwards.
 * @param lst A pointer to the top of the linked list to search.
 * @param threshold The threshold value to compare against.
 * @param smaller Flag indicating whether to look for values smaller (1)
 * or larger (0) than threshold.
 * @return Number of reverse rotations needed, or 0 if no valid number found.
 *
 * This helper function calculates how many reverse rotations (rra)
 * would be needed
 * to reach the next number that meets the threshold condition. It:
 * 1. Starts from the beginning of the list
 * 2. For each position, checks remaining nodes for valid numbers
 * 3. If no valid numbers remain after current position, returns steps needed
 * 4. Otherwise continues checking next position
 *
 * The smaller parameter controls the comparison:
 * - If smaller=1, looks for numbers < threshold
 * - If smaller=0, looks for numbers >= threshold
 */
static unsigned int	calculate_next_rrotation(t_list *lst, int threshold,
											int smaller)
{
	unsigned int	reverse_rotations;
	int				has_next_int;

	reverse_rotations = ft_lstsize(lst);
	has_next_int = 0;
	while (lst)
	{
		if (has_next_int == 0)
			has_next_int = has_int_within_bound(lst, threshold, smaller);
		if (has_next_int == -1)
			return (reverse_rotations);
		reverse_rotations--;
		if ((smaller && get_content(lst, 1) < threshold)
			|| (!smaller && get_content(lst, 1) >= threshold))
			has_next_int = 0;
		lst = lst->next;
	}
	return (0);
}

/**
 * @brief Finds the most efficient direction to reach the next number
 * meeting a threshold condition.
 * @param lst A pointer to the top of the linked list to search.
 * @param threshold The threshold value to compare against.
 * @param smaller Flag indicating whether to look for values smaller (1)
 * or larger (0) than threshold.
 * @return 1 if rotating forward is optimal, 2 if rotating backward is optimal,
 * -1 if no valid number found.
 *
 * This function determines whether it's more efficient to
 * rotate forward (ra) or backward (rra) to reach the next number
 * that is either smaller or larger than
 * the threshold value 'threshold'. It does this by:
 * 1. Counting steps forward until finding a valid number
 * 2. Using get_next_rrotation() to count steps backward
 * until finding a valid number
 * 3. Comparing the two counts to determine the optimal rotation direction
 *
 * The smaller parameter controls the comparison:
 * - If smaller=1, looks for numbers < threshold
 * - If smaller=0, looks for numbers >= threshold
 */
int	calculate_next_rotation(t_list *lst, int threshold, int smaller)
{
	unsigned int	rotations;
	unsigned int	reverse_rotations;
	t_list			*current;

	rotations = 0;
	current = lst;
	while (current)
	{
		if ((smaller && get_content(current, 1) < threshold)
			|| (!smaller && get_content(current, 1) >= threshold))
			break ;
		rotations++;
		current = current->next;
	}
	if (!current)
		return (-1);
	reverse_rotations = calculate_next_rrotation(lst, threshold, smaller);
	if (rotations <= reverse_rotations)
		return (1);
	return (2);
}
