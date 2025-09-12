/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:47:21 by marlee            #+#    #+#             */
/*   Updated: 2025/09/12 15:59:53 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_list	*stk_a;
	t_list	*stk_b;
	int		status;

	stk_a = NULL;
	stk_b = NULL;
	status = check_and_populate(&stk_a, argc, argv);
	if (status == 1)
		return (ft_putstr_fd("Error\n", 2),
			ft_lstclear(&stk_a, free_int_content), 1);
	else if (status == 1 && !(stk_a == NULL))
		return (ft_putstr_fd("Error\n", 2),
			ft_lstclear(&stk_a, free_int_content), 1);
	norm_and_index(stk_a);
	if (is_sorted(stk_a))
		return (ft_lstclear(&stk_a, free_int_content), 0);
	choose_sort(&stk_a, &stk_b);
	return (ft_lstclear(&stk_a, free_int_content), 0);
}
