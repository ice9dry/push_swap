/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:03:34 by marlee            #+#    #+#             */
/*   Updated: 2025/09/03 11:49:24 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_rotate.h"

//Shifts last element to the top.
void	reverse_rotate(t_list **stack)
{
	t_list	*last_node;
	t_list	*second_last_node;

	if (!*stack || !(*stack)->next)
	{
		ft_printf("NOTHING TO DO! Remove this before submission!\n");
		return ;
	}
	second_last_node = *stack;
	while (second_last_node->next->next != NULL)
		second_last_node = second_last_node->next;
	last_node = second_last_node->next;
	last_node->next = *stack;
	*stack = last_node;
	second_last_node->next = NULL;
}

void	rra(t_list **stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	rrb(t_list **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	rrr(t_list **stk_a, t_list **stk_b)
{
	reverse_rotate(stk_a);
	reverse_rotate(stk_b);
	ft_printf("rrr\n");
}
