/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marklee <marklee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:25:22 by marlee            #+#    #+#             */
/*   Updated: 2026/11/05 17:00:41 by marklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix_sort.h"
#include "is_sorted.h"

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

static void	process_stack_a(t_list **a, t_list **b, int bit, int *count) // Can remove count
{
	int		size;
	int		j;
	t_data	*data;

	size = ft_lstsize(*a);
	j = -1;
	while (++j < size && !is_sorted(*a))
	{
		data = (t_data *)(*a)->content;
		if (((data->index >> bit) & 1) == 0)
		{
			if (j == size - 1)
				break ;
			pb(a, b);
			(*count)++;
		}
		else
			ra(a);
	}
}

static void	process_stack_b(t_list **a, t_list **b, int bit, int last_bit)
{
	int		k;
	int		size;
	t_data	*data;

	k = -1;
	size = ft_lstsize(*b);
	if (bit < last_bit)
	{
		while (++k < size)
		{
			data = (t_data *)(*b)->content;
			if (((data->index >> (bit + 1)) & 1) == 0)
				rb(b);
			else
				pa(a, b);
		}
	}
	else
		while (*b)
			pa(a, b);
}

void	radix_sort(t_list **stk_a, t_list **stk_b)
{
	int	i;
	int	count; // Can remove this
	int	max_bits;

	// Get the number of bits that the index would use
	// If there are 6 to 8 integers, then max_bits is 3, i.e. 2^3 = 8
	// If there are 9 to 16 integers, then max_bits is 4, i.e. 2^4 = 16
	// If there are 17 to 32 integers, then max_bits is 4, i.e. 2^5 = 32
	max_bits = get_max_bits(ft_lstsize(*stk_a));
	i = -1;
	while (++i < max_bits)
	{
		count = 0; // Can remove this
		process_stack_a(stk_a, stk_b, i, &count); // Can remove count
		process_stack_b(stk_a, stk_b, i, max_bits - 1);
	}
}
