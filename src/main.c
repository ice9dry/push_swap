/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marklee <marklee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:47:21 by marlee            #+#    #+#             */
/*   Updated: 2026/11/05 15:37:10 by marklee          ###   ########.fr       */
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
	// check arguments if okay, populate stk_a with arguments
	status = check_and_populate(&stk_a, argc, argv);
	// Error status 1 and 2 means the parameters are not ok e.g. non-integers or empty string
	if (status == 1 || status == 2)
		// Last parameter should use status instead
		return (ft_putstr_fd("Error\n", 2),	ft_lstclear(&stk_a, free_int_content), 1);
	// Error status 3 means there is no arguments
	if (status == 3)
		// Last parameter should use status instead
		return (ft_lstclear(&stk_a, free_int_content), 3);
	norm_and_index(stk_a);
	// Check if the stack is sorted. If it is, clear (free)
	// the linked list and return 0
	if (is_sorted(stk_a))
		return (ft_lstclear(&stk_a, free_int_content), 0);
	// Start the push swap process
	choose_sort(&stk_a, &stk_b);
	return (ft_lstclear(&stk_a, free_int_content), 0);
}
