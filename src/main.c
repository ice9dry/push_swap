/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:47:21 by marlee            #+#    #+#             */
/*   Updated: 2025/09/01 18:57:56 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_utils1.h"
#include "ft_lst_base.h"
#include "ft_lst_ops.h"
#include "struct.h"

int	main(int argc, char **argv)
{
	t_list	*head;

	head = NULL;
	if (argc < 2)
		return (printf("Error"), -1);
	populate_list(&head, argc, argv);
	printlist(head);
	return (ft_lstclear(&head, ft_free_int_content), 0);
}
