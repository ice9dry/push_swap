/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:25:22 by marlee            #+#    #+#             */
/*   Updated: 2025/09/12 12:21:43 by marlee           ###   ########.fr       */
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

static void	process_stack_a(t_list **a, t_list **b, int bit, int *count)
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
	int	count;
	int	max_bits;

	max_bits = get_max_bits(ft_lstsize(*stk_a));
	i = -1;
	while (++i < max_bits)
	{
		count = 0;
		process_stack_a(stk_a, stk_b, i, &count);
		process_stack_b(stk_a, stk_b, i, max_bits - 1);
	}
}
