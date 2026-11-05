/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marklee <marklee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:23:47 by marlee            #+#    #+#             */
/*   Updated: 2026/11/05 15:38:23 by marklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choose_sort.h"

// For 2 to 5 integers, a hard coded sort is used.
// for 6 integers and above, the radix sort is used.
void	choose_sort(t_list **stk_a, t_list **stk_b)
{
	if (ft_lstsize(*stk_a) == 1)
		return ;
	else if (ft_lstsize(*stk_a) == 2)
		sa(stk_a);
	else if (ft_lstsize(*stk_a) == 3)
		three_sort(stk_a);
	else if (ft_lstsize(*stk_a) == 4)
		four_sort(stk_a, stk_b);
	else if (ft_lstsize(*stk_a) == 5)
		five_sort(stk_a, stk_b);
	else if (ft_lstsize(*stk_a) >= 6)
		radix_sort(stk_a, stk_b);
}
