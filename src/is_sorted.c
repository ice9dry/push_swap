/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:58:36 by marlee            #+#    #+#             */
/*   Updated: 2025/09/05 15:05:15 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_sorted.h"

int is_sorted(t_list *stack)
{
	// A list with 0 or 1 element is considered sorted.
	if (!stack || !stack->next)
		return (1);

	while (stack->next)
	{
		// Get the values from the t_node_data structs
		if (((t_data *)stack->content)->value > \
			((t_data *)stack->next->content)->value)
		{
			return (0); // Return false if an element is greater than the next
		}
		stack = stack->next;
	}
	return (1); // Return true if the loop completes
}