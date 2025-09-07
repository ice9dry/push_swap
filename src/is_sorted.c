/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:58:36 by marlee            #+#    #+#             */
/*   Updated: 2025/09/07 18:20:17 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_sorted.h"

int	is_sorted(t_list *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (((t_data *)stack->content)->value
			> ((t_data *)stack->next->content)->value)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}
