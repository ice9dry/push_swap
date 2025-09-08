/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_to_five_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:38:39 by marlee            #+#    #+#             */
/*   Updated: 2025/09/08 21:46:25 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three_to_five_sort.h"

static int	find_min_pos(t_list **stack)
{
	int		min_index;
	int		min_pos;
	int		pos;
	t_list	*current;

	if (!*stack)
		return (-1);
	min_index = ((t_data *)(*stack)->content)->index;
	min_pos = 0;
	pos = 0;
	current = *stack;
	while (current)
	{
		if (((t_data *)current->content)->index < min_index)
		{
			min_index = ((t_data *)current->content)->index;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

void	four_sort(t_list **stk_a, t_list **stk_b)
{
	int	pos;

	pos = find_min_pos(stk_a);
	if (pos == 1)
		sa(stk_a);
	else if (pos == 2)
	{
		ra(stk_a);
		ra(stk_a);
	}
	else if (pos == 3)
		rra(stk_a);
	pb(stk_a, stk_b);
	three_sort(stk_a);
	pa(stk_a, stk_b);
}

void	five_sort(t_list **stk_a, t_list **stk_b)
{
	int	pos;

	pos = find_min_pos(stk_a);
	while (((t_data *)(*stk_a)->content)->index != 0)
	{
		if (pos <= 2)
			ra(stk_a);
		else
			rra(stk_a);
		pos = find_min_pos(stk_a);
	}
	pb(stk_a, stk_b);
	pos = find_min_pos(stk_a);
	while (((t_data *)(*stk_a)->content)->index != 1)
	{
		if (pos <= 2)
			ra(stk_a);
		else
			rra(stk_a);
		pos = find_min_pos(stk_a);
	}
	pb(stk_a, stk_b);
	three_sort(stk_a);
	pa(stk_a, stk_b);
	pa(stk_a, stk_b);
}

void	three_sort(t_list **stk_a)
{
	int	first_index;
	int	second_index;
	int	third_index;

	first_index = ((t_data *)(*stk_a)->content)->index;
	second_index = ((t_data *)(*stk_a)->next->content)->index;
	third_index = ((t_data *)(*stk_a)->next->next->content)->index;
	if (first_index < second_index && second_index < third_index)
		return ;
	if (first_index < third_index && third_index < second_index)
	{
		rra(stk_a);
		sa(stk_a);
	}
	else if (second_index < first_index && first_index < third_index)
		sa(stk_a);
	else if (second_index < third_index && third_index < first_index)
		ra(stk_a);
	else if (third_index < first_index && first_index < second_index)
		rra(stk_a);
	else if (third_index < second_index && second_index < first_index)
	{
		ra(stk_a);
		sa(stk_a);
	}
}
