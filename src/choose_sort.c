/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:23:47 by marlee            #+#    #+#             */
/*   Updated: 2025/09/05 17:41:15 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choose_sort.h"

void	choose_sort(t_list **stk_a, t_list **stk_b)
{
	if (ft_lstsize(*stk_a) == 2)
		sa(stk_a);
	if (ft_lstsize(*stk_a) == 3)
		three_sort(stk_a);
	if (ft_lstsize(*stk_a) > 3)
		radix_sort(stk_a, stk_b);
}