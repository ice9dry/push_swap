/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:03:34 by marlee            #+#    #+#             */
/*   Updated: 2025/09/02 19:06:51 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include "libft.h"
#include "ft_printf.h"

void	swap(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;

	if (!*stack || !(*stack)->next)
	{	
		ft_printf("NOTHING TO DO! Remove this before submission!\n");
		return ;
	}
	first_node = *stack;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
}

void	sa(t_list **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_list **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	ss(t_list **stk_a, t_list **stk_b)
{
	swap(stk_a);
	swap(stk_b);
	ft_printf("ss\n");
}