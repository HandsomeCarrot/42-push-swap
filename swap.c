/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:07:31 by vpoka             #+#    #+#             */
/*   Updated: 2025/01/24 15:22:53 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * sa - Swap the first two elements at the top of stack 'a'.
 * @param a: Pointer to stack 'a' structure
 *
 * This function swaps the first two elements of the stack 'a'.
 * If the stack contains less than two elements, no operation is performed.
 */
void	sa(t_stack *a)
{
	void	*temp;

	if (a && a->size > 2)
	{
		temp = a->top->content;
		a->top->content = a->top->next->content;
		a->top->next->content = temp;
		write(1, "sa\n", sizeof(char) * 3);
	}
}

/**
 * @brief Swaps the first two elements at the top of the stack 'b'.
 * 
 * This function takes a pointer to the stack 'b' structure and swaps
 * the first two elements at the top of the stack. If the stack contains
 * fewer than two elements, no action is performed.
 * 
 * @param b Pointer to stack 'b' structure
 */
void	sb(t_stack *b)
{
	void	*temp;

	if (b && b->size > 2)
	{
		temp = b->top->content;
		b->top->content = b->top->next->content;
		b->top->next->content = temp;
		write(1, "sb\n", sizeof(char) * 3);
	}
}

/**
 * ss - Swaps the first two elements of both stacks a and b.
 * @param a: Pointer to stack 'a' structure
 * @param b: Pointer to stack 'b' structure
 *
 * This function performs a simultaneous swap of the first two elements
 * of both stacks a and b. If either stack has fewer than two elements,
 * no operation is performed on that stack.
 */
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
