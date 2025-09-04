/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:47:21 by marlee            #+#    #+#             */
/*   Updated: 2025/09/05 01:07:05 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_list	*stk_a;
	t_list	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (!check_and_populate(&stk_a, argc, argv))
		printlist(stk_a);
	else
		return (ft_printf("Error\n"), ft_lstclear(&stk_a, free_int_content), 1);
			// turk_sort(&stk_a, &stk_b);
	norm_and_index(stk_a);
			// ra(&stk_a);
	radix_sort(&stk_a, &stk_b);
	printlistboth(stk_a, stk_b);
	// ra(&stk_a);
	// printlistboth(stk_a, stk_b);
	// pb(&stk_a, &stk_b);
	// printlistboth(stk_a, stk_b);
	// pb(&stk_a, &stk_b);
	// printlistboth(stk_a, stk_b);
	// rb(&stk_b);
	// printlistboth(stk_a, stk_b);
	// rr(&stk_a, &stk_b);
	// printlistboth(stk_a, stk_b);
	// rra(&stk_a);
	// printlistboth(stk_a, stk_b);
	// rrb(&stk_b);
	// printlistboth(stk_a, stk_b);
	// rrr(&stk_a, &stk_b);
	// printlistboth(stk_a, stk_b);
	// pa(&stk_a, &stk_b);
	// printlistboth(stk_a, stk_b);
	// sa(&stk_a);
	// printlistboth(stk_a, stk_b);
	// sb(&stk_b);
	// printlistboth(stk_a, stk_b);
	// pa(&stk_a, &stk_b);
	// printlistboth(stk_a, stk_b);
	// ss(&stk_a, &stk_b);
	// printlistboth(stk_a, stk_b);
	return (ft_lstclear(&stk_a, free_int_content), 0);
}
