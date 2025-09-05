/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:35:55 by marlee            #+#    #+#             */
/*   Updated: 2025/09/05 14:45:30 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix_sort.h"

void	radix_sort_3(t_list **stk_a, t_list **stk_b)
{
	t_data	*data;
	int		max_bits = 0;
	int		total_size = ft_lstsize(*stk_a);
	int		i = 0;
	int		j;
	int		active_size;

	// Calculate maximum bits needed to represent index
	while ((total_size - 1) >> max_bits)
		max_bits++;

	while (i < max_bits)
	{

		if (i % 2 == 0)
		{
			// Even pass: process stk_a to stk_b
			active_size = ft_lstsize(*stk_a);
			j = 0;
			while (j++ < active_size)
			{
				data = (t_data *)(*stk_a)->content;
				if (((data->index >> i) & 1) == 0)
					pb(stk_a, stk_b);
				else
					ra(stk_a);
			}
		}
		else
		{
			active_size = ft_lstsize(*stk_b);
			j = 0;
			// Odd pass: process stk_b to stk_a
			while (j++ < active_size)
			{
				data = (t_data *)(*stk_b)->content;
				if (((data->index >> i) & 1) == 0)
					pa(stk_a, stk_b);
				else
					rb(stk_b);
			}
		}
		i++;
	}
	// Ensure all elements are in stk_a at the end
	if (ft_lstsize(*stk_b) > 0)
	{
		while (*stk_b)
			pa(stk_a, stk_b);
	}
	printf("End of sort\n");
}
