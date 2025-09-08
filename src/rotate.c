/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:03:34 by marlee            #+#    #+#             */
/*   Updated: 2025/09/08 22:16:40 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate.h"

void	rotate(t_list **stack)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = ft_lstlast(*stack);
	last_node->next = first_node;
	*stack = first_node->next;
	first_node->next = NULL;
}

void	ra(t_list **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_list **stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	rr(t_list **stk_a, t_list **stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
	ft_printf("rr\n");
}
