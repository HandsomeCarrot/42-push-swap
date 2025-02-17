/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:08:03 by vpoka             #+#    #+#             */
/*   Updated: 2025/01/24 17:01:57 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes the top element from b to a
 * 
 * @param a Pointer to stack A
 * @param b Pointer to stack B
 */
void	pa(t_stack *a, t_stack *b)
{
	t_list	*node;

	node = pull(b);
	if (node)
	{
		push(a, node);
		write(1, "pa\n", sizeof(char) * 3);
	}
}

/**
 * @brief Pushes the top element from a to b
 * 
 * @param a Pointer to stack A
 * @param b Pointer to stack B
 */
void	pb(t_stack *a, t_stack *b)
{
	t_list	*node;

	node = pull(a);
	if (node)
	{
		push(b, node);
		write(1, "pb\n", sizeof(char) * 3);
	}
}
