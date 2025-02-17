/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:36:26 by vpoka             #+#    #+#             */
/*   Updated: 2025/01/27 17:40:33 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates optimal chunk size based on list size
 * 
 * Determines the chunk size used for sorting optimization:
 * - 25 elements for lists up to 100
 * - 50 elements for lists up to 500
 * - Dynamic sizing (list_size/15) for larger lists
 * 
 * @param lst_size Total number of elements in the list
 * @return int Calculated chunk size
 */
static int	calc_chunksize(unsigned int lst_size)
{
	if (lst_size <= 100)
		return (25);
	else if (lst_size <= 500)
		return (50);
	return (lst_size / 15);
}

/**
 * @brief Splits stack A into chunks in stack B for sorting
 * 
 * Implements the chunk-based sorting algorithm:
 * 1. Calculates initial chunk range based on list size
 * 2. Processes stack A pushing elements within current chunk to B
 * 3. Rotates elements in B when below chunk midpoint
 * 4. Expands chunk range when current chunk is processed
 * 
 * @param a Pointer to stack A (main stack)
 * @param b Pointer to stack B (helper stack)
 */
void	split_a(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	rotation;

	chunk_size = calc_chunksize(a->size);
	lst_min_max(a->top, &chunk_min, NULL, 1);
	chunk_max = chunk_min + chunk_size;
	while (a && a->size > 0)
	{
		rotation = calculate_next_rotation(a->top, chunk_max + 1, 1);
		if (rotation < 0)
		{
			chunk_min = chunk_max;
			chunk_max += chunk_size;
		}
		while (rotation == 1 && peek(a) > chunk_max)
			ra(a);
		while (rotation == 2 && peek(a) > chunk_max)
			rra(a);
		if (peek(a) <= chunk_max)
			pb(a, b);
		if (peek(b) < (chunk_max + chunk_min) / 2)
			rb(b);
	}
}
