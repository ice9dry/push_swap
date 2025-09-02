/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:06:35 by marlee            #+#    #+#             */
/*   Updated: 2025/09/02 10:54:21 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "utils1.h"

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

int	free_split_array(char **array)
{
	int	i;

	if (!array)
		return (1);
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

int	populate_list_from_array(t_list **start, int count, char **array)
{
	int i;
	int *num_ptr;

	i = 0;
	while (i < count)
	{
		num_ptr = malloc(sizeof(int));
		if (!num_ptr)
			return (1);
		*num_ptr = ft_atoi(array[i]);
		ft_lstadd_back(start, ft_lstnew(num_ptr));
		i++;
	}
	return (0);
}
int	populate_from_single_string(t_list **start, char *arg_str)
{
	char	**split_array;
	int		count;
	int		status;

	split_array = ft_split(arg_str, ' ');
	if (!split_array)
		return (1);
	count = 0;
	while (split_array[count])
		count++;
	status = populate_list_from_array(start, count, split_array);
	free_split_array(split_array);
	return (status);
}
int	check_and_populate(t_list **start, int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (argc == 2)
		return (populate_from_single_string(start, argv[1]));
	else
		return (populate_list_from_array(start, argc - 1, argv + 1));
}