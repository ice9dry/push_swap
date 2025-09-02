/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:47:21 by marlee            #+#    #+#             */
/*   Updated: 2025/09/02 10:41:58 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "utils1.h"
#include "ft_printf.h"

int	check_and_populate(t_list **start, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_list	*head;

	head = NULL;
	if (argc < 2)
		return (ft_printf("Error\n"), -1);
	check_and_populate(&head, argc, argv);
	printlist(head);
	return (ft_lstclear(&head, ft_free_int_content), 0);
}
