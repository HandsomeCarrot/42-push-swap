/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:07:59 by vpoka             #+#    #+#             */
/*   Updated: 2025/02/18 15:25:37 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

//--------stack.c--------//

typedef struct s_stack
{
	t_list			*top;
	unsigned int	size;
}					t_stack;

t_stack				*new_stack(t_list *lst);
void				push(t_stack *stack, t_list *node);
t_list				*pull(t_stack *stack);
int					peek(t_stack *stack);
void				free_stacks(t_stack *a, t_stack *b, t_list	**lst);

//--------swap.c--------//

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

//--------push.c--------//

void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

//--------rotate.c--------//

void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

//--------reverse_rotate.c--------//

void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

//--------list.c--------//

t_list				*create_list(int ac, char **av);

//--------sort.c--------//

void				sort_stack(t_stack *a, t_stack *b);

//--------normalize.c--------//

int					normalize_stack(t_list *lst, unsigned int size);

//--------split.c--------//

void				split_a(t_stack *a, t_stack *b);

//--------rotations.c--------//

int					calculate_next_rotation(t_list *lst, int threshold,
						int smaller);

//--------utils.c--------//

int					get_content(t_list *node, int normalized);
void				set_content(t_list *node, int new_cont, int normalized);
void				lst_min_max(t_list *lst, int *min, int *max,
						int normalized);
int					lst_sorted(t_list *lst);
int					list_has_duplicates(t_list *lst);

#endif
