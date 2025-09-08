/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:01:55 by marlee            #+#    #+#             */
/*   Updated: 2025/09/08 10:11:59 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push(t_list **src_stack, t_list **dst_stack)
{
	t_list	*node_to_push;

	if (!*src_stack)
		return ;
	node_to_push = *src_stack;
	*src_stack = (*src_stack)->next;
	node_to_push->next = NULL;
	ft_lstadd_front(dst_stack, node_to_push);
}

void	pa(t_list **stk_a, t_list **stk_b)
{
	push(stk_b, stk_a);
	ft_printf("pa\n");
}

void	pb(t_list **stk_a, t_list **stk_b)
{
	push(stk_a, stk_b);
	ft_printf("pb\n");
}
