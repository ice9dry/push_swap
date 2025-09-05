/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:38:39 by marlee            #+#    #+#             */
/*   Updated: 2025/09/05 17:39:51 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three_sort.h"

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
