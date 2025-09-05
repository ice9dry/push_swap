/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:25:22 by marlee            #+#    #+#             */
/*   Updated: 2025/09/05 11:20:55 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix_sort.h"

void radix_sort_2(t_list **stk_a, t_list **stk_b)
{
	t_data *data;
	int max_bits;
	int i;
	int j;
	int size;

	size = ft_lstsize(*stk_a);
	if (size <= 1)
		return;
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (i % 2 == 0) // Even pass: read from A, push to B
			{
				ft_printf("odd SORT");
				data = (t_data *)(*stk_a)->content;
				if (((data->index >> i) & 1) == 1)
					pb(stk_a, stk_b);
				else
					ra(stk_a);
			}
			else // Odd pass: read from B, push to A
			{
				ft_printf("even SORT");
				data = (t_data *)(*stk_b)->content;
				if (((data->index >> i) & 1) == 1)
					pa(stk_a, stk_b); // Note the reversed arguments
				else
					rb(stk_b);
			}
			j++;
		}
		i++;
	}
	// Final check: if the last pass was odd, the sorted stack is in B.
	// Push everything back to A.
	ft_printf("PARTIAL SORT COMPLETED");
	if (max_bits % 2 != 0)
	{
		while (*stk_b)
			pa(stk_a, stk_b);
	}
}