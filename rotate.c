/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:08:10 by vpoka             #+#    #+#             */
/*   Updated: 2025/01/24 16:46:03 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Rotates stack A (shift all elements up by one, first becomes last)
 * @param a Pointer to stack A structure
 * @note Only performs rotation if stack has more than one element
 * @note Prints "ra" to stdout after rotation
 */
void	ra(t_stack *a)
{
	t_list	*new_last;

	if (a && a->size > 1)
	{
		new_last = a->top;
		a->top = new_last->next;
		new_last->next = NULL;
		ft_lstadd_back(&(a->top), new_last);
		write(1, "ra\n", sizeof(char) * 3);
	}
}

/**
 * Rotates stack B (shift all elements up by one, first becomes last)
 * @param b Pointer to stack B structure
 * @note Only performs rotation if stack has more than one element
 * @note Prints "rb" to stdout after rotation
 */
void	rb(t_stack *b)
{
	t_list	*new_last;

	if (b && b->size > 1)
	{
		new_last = b->top;
		b->top = new_last->next;
		new_last->next = NULL;
		ft_lstadd_back(&(b->top), new_last);
		write(1, "rb\n", sizeof(char) * 3);
	}
}

/**
 * rr - Rotates both stacks a and b simultaneously.
 * @param a: Double pointer to the first stack.
 * @param b: Double pointer to the second stack.
 *
 * This function performs a rotation on both stacks a and b. The first element
 * of each stack becomes the last one, and all other elements are shifted up
 * by one position.
 */
void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
