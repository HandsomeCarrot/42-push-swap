/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:08:07 by vpoka             #+#    #+#             */
/*   Updated: 2025/01/24 17:00:22 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Reverse rotates stack A - moves the last element to the top
 *
 * @param a Pointer to stack A
 * @return void
 *
 * @note Prints "rra" to stdout after execution
 * @note Only operates if stack has more than 1 element
 */
void	rra(t_stack *a)
{
	t_list	*new_first;
	t_list	*new_last;

	if (a && a->size > 1)
	{
		new_first = ft_lstlast(a->top);
		new_last = a->top;
		ft_lstadd_front(&(a->top), new_first);
		while (new_last && new_last->next != a->top)
			new_last = new_last->next;
		new_last->next = NULL;
		write(1, "rra\n", sizeof(char) * 4);
	}
}

/**
 * @brief Reverse rotates stack B - moves the last element to the top
 *
 * @param b Pointer to stack B
 * @return void
 *
 * @note Prints "rrb" to stdout after execution
 * @note Only operates if stack has more than 1 element
 */
void	rrb(t_stack *b)
{
	t_list	*new_first;
	t_list	*new_last;

	if (b && b->size > 1)
	{
		new_first = ft_lstlast(b->top);
		new_last = b->top;
		ft_lstadd_front(&(b->top), new_first);
		while (new_last && new_last->next != b->top)
			new_last = new_last->next;
		new_last->next = NULL;
		write(1, "rrb\n", sizeof(char) * 4);
	}
}

/**
 * @brief Executes both rra and rrb operations
 *
 * @param a Pointer to stack A
 * @param b Pointer to stack B
 * @return void
 *
 * @note Prints "rrr" to stdout after execution
 * @note Only operates if both stacks have more than 1 element
 */
void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
