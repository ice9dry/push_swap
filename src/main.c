/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:47:21 by marlee            #+#    #+#             */
/*   Updated: 2025/09/01 18:52:08 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_utils1.h"
#include "ft_lst_base.h"
#include "ft_lst_ops.h"
#include "struct.h"

void	printlist(t_list *current)
{
	while (current)
	{
		printf("%d -> ", *(int *)current->content);
		current = current->next;
	}
	printf("NULL\n");
}

int	populate_list(t_list **start, int argc, char **argv)
{
	int i;
	int *num_ptr;

	i = 1;
	while (i < argc)
	{
		num_ptr = malloc(sizeof(int));
		if (!num_ptr)
			return (1);
		*num_ptr = ft_atoi(argv[i]);
		ft_lstadd_back(start, ft_lstnew(num_ptr));
		i++;
	}
	return (0);
}

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
