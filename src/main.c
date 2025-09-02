/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:47:21 by marlee            #+#    #+#             */
/*   Updated: 2025/09/02 21:37:22 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "utils1.h"
#include "ft_printf.h"
#include "push.h"
#include "rotate.h"
#include "reverse_rotate.h"
#include "swap.h"

int	main(int argc, char **argv)
{
	t_list	*stk_a;
	t_list	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (!check_and_populate(&stk_a, argc, argv))
		printlist(stk_a);
	// ra(&stk_a);
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
	return (ft_lstclear(&stk_a, ft_free_int_content), 0);
}
