/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:57:44 by vpoka             #+#    #+#             */
/*   Updated: 2025/01/27 17:40:25 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts a stack of 3 elements
 * 
 * @param a Stack to sort. Must have exactly 3 elements.
 * 1. Finds maximum value in stack
 * 2. Rotates max to bottom if needed
 * 3. Performs final swap if necessary
 */
static void	sort_3(t_stack *a)
{
	int	max;

	lst_min_max(a->top, NULL, &max, 1);
	if (peek(a) == max)
		ra(a);
	else if (get_content(a->top->next, 1) == max)
		rra(a);
	if (!lst_sorted(a->top))
		sa(a);
}

/**
 * @brief Handles sorting of small stacks (2-5 elements)
 * 
 * @param a Main stack
 * @param b Helper stack
 * 1. Directly sorts 2-3 elements
 * 2. For 4-5 elements:
 *    a) Pushes smallest elements to B
 *    b) Sorts remaining 3 in A
 *    c) Merges back from B
 */
static void	handle_small_groups(t_stack *a, t_stack *b)
{
	int	min;
	int	rotation;

	if (a->size == 2)
		sa(a);
	if (a->size == 3)
		sort_3(a);
	else if (a->size <= 5)
	{
		while (a->size > 3)
		{
			lst_min_max(a->top, &min, NULL, 1);
			rotation = calculate_next_rotation(a->top, min + 1, 1);
			if (rotation < 0)
				break ;
			while (rotation == 1 && peek(a) != min)
				ra(a);
			while (rotation == 2 && peek(a) != min)
				rra(a);
			pb(a, b);
		}
		sort_3(a);
		while (b->size > 0)
			pa(a, b);
	}
}

/**
 * @brief Merges sorted elements from B back into A
 * 
 * @param a Pointer to main stack (receiving sorted elements)
 * @param b Pointer to helper stack (being emptied)
 * 1. Finds current max in B
 * 2. Rotates B to bring max to top
 * 3. Pushes max to A
 * Repeats until B is empty
 */
static void	sort_b_in_a(t_stack *a, t_stack *b)
{
	int	max;
	int	rotation;

	while (b->size > 0)
	{
		lst_min_max(b->top, NULL, &max, 1);
		rotation = calculate_next_rotation(b->top, max, 0);
		if (rotation < 0)
			break ;
		while (rotation == 1 && peek(b) != max)
			rb(b);
		while (rotation == 2 && peek(b) != max)
			rrb(b);
		pa(a, b);
	}
}

/**
 * @brief Main sorting entry point
 * 
 * @param a Main stack to sort
 * @param b Helper stack
 * Handles two cases:
 * 1. Small stacks (≤5 elements): Direct sorting
 * 2. Larger stacks: 
 *    a) Normalize values
 *    b) Split into chunks
 *    c) Merge back sorted
 */
void	sort_stack(t_stack *a, t_stack *b)
{
	normalize_stack(a->top, a->size);
	if (a->size <= 5)
		handle_small_groups(a, b);
	else
	{
		split_a(a, b);
		sort_b_in_a(a, b);
	}
}
