/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:02:16 by marlee            #+#    #+#             */
/*   Updated: 2025/09/03 11:29:12 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printout_utils.h"

void	printlist(t_list *current)
{
	while (current)
	{
		printf("%d -> ", *(int *)current->content);
		current = current->next;
	}
	printf("NULL\n");
}

void	printlistboth(t_list *stk_a, t_list *stk_b)
{
	ft_printf("Stack A: ");
	printlist(stk_a);
	ft_printf("Stack B: ");
	printlist(stk_b);
}
