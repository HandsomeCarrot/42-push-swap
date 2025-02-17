/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:41:18 by vpoka             #+#    #+#             */
/*   Updated: 2025/01/30 14:28:51 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Creates a new stack structure from a linked list
 * @param lst Pointer to the first node of a linked list (can be NULL)
 * @return Pointer to the newly created stack, or NULL if allocation fails
 */
t_stack	*new_stack(t_list *lst)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	if (lst)
	{
		stack->top = lst;
		stack->size = ft_lstsize(lst);
	}
	else
	{
		stack->top = NULL;
		stack->size = 0;
	}
	return (stack);
}

/**
 * Pushes a node onto the top of the stack
 * @param stack Pointer to the stack structure
 * @param node Pointer to the node to push
 */
void	push(t_stack *stack, t_list *node)
{
	if (!node)
		return ;
	ft_lstadd_front((t_list **)stack, node);
	stack->size++;
}

/**
 * Removes and returns the top node from the stack
 * @param stack Pointer to the stack structure
 * @return Pointer to the removed node, or NULL if stack is empty
 */
t_list	*pull(t_stack *stack)
{
	t_list	*temp;

	if (!stack || !stack->top)
		return (NULL);
	temp = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	return (temp);
}

/**
 * Returns the value of the top node without removing it
 * @param stack Pointer to the stack structure
 * @return Value of the top node, or 0 if stack is empty
 */
int	peek(t_stack *stack)
{
	if (!stack || !stack->top)
		return (0);
	return (get_content(stack->top, 1));
}

/**
 * Frees memory allocated for both stacks
 * @param a Pointer to the first stack (can be NULL)
 * @param b Pointer to the second stack (can be NULL)
 */
void	free_stacks(t_stack *a, t_stack *b, t_list **lst)
{
	if (a)
	{
		ft_lstclear(&(a->top), &free);
		free(a);
		a = NULL;
	}
	else if (lst && *lst)
		ft_lstclear(lst, &free);
	if (b)
	{
		ft_lstclear(&(b->top), &free);
		free(b);
		b = NULL;
	}
}
