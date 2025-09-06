/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_to_five_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:38:39 by marlee            #+#    #+#             */
/*   Updated: 2025/09/06 09:43:51 by marlee           ###   ########.fr       */
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

static void	get_indices(int *array, t_list **stk_a)
{
	t_list	*current;
	int		i;

	current = *stk_a;
	i = 0;
	while (current)
	{
		array[i] = ((t_data *)current->content)->index;
		i++;
		current = current->next;
	}
}

static void	handle_three_sort_cases(int *array, t_list **stk_a)
{
	if (array[0] == 0)
	{
		rra(stk_a);
		sa(stk_a);
	}
	else if (array[0] == 1)
	{
		if (array[1] == 2)
			rra(stk_a);
		else
			sa(stk_a);
	}
	else if (array[0] == 2)
	{
		if (array[1] == 0)
			ra(stk_a);
		else
		{
			ra(stk_a);
			sa(stk_a);
		}
	}
}

void	three_sort(t_list **stk_a)
{
	int	array[3];

	get_indices(array, stk_a);
	handle_three_sort_cases(array, stk_a);
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
