/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:47:21 by marlee            #+#    #+#             */
/*   Updated: 2025/08/29 18:53:18 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	printlist(t_list *current)
{
	while (current)
	{
		printf("%d -> ", *(int *)current->content);
		current = current->next;
	}
	printf("NULL\n");
}

int	main(int argc, char **argv)
{
	int		*num_ptr;
	int		i;
	t_list	*head;
	t_list	*current;

	i = 1;
	head = NULL;
	if (argc < 2)
		return (printf("Error"), -1);
	while (i < argc)
	{
		num_ptr = malloc(sizeof(int));
		if (!num_ptr)
			return (1);
		*num_ptr = ft_atoi(argv[i]);
		ft_lstadd_back(&head, ft_lstnew(num_ptr));
		i++;
	}
	printlist(head);
	return (ft_lstclear(&head, ft_free_int_content), 0);
}
