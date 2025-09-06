/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:47:21 by marlee            #+#    #+#             */
/*   Updated: 2025/09/06 10:02:50 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_list	*stk_a;
	t_list	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (check_and_populate(&stk_a, argc, argv))
		return (ft_printf("Error\n"), ft_lstclear(&stk_a, free_int_content), 1);
	norm_and_index(stk_a);
	if (is_sorted(stk_a))
		return (ft_lstclear(&stk_a, free_int_content), 0);
	choose_sort(&stk_a, &stk_b);
	return (ft_lstclear(&stk_a, free_int_content), 0);
}
