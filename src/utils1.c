/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:06:35 by marlee            #+#    #+#             */
/*   Updated: 2025/09/02 08:36:50 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "utils1.h"

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

void	printlist(t_list *current)
{
	while (current)
	{
		printf("%d -> ", *(int *)current->content);
		current = current->next;
	}
	printf("NULL\n");
}

void	ft_free_int_content(void *content)
{
	free(content);
}
