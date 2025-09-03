/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:06:35 by marlee            #+#    #+#             */
/*   Updated: 2025/09/03 10:56:05 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "utils1.h"
#include "utils2.h"
#include "ft_printf.h"

static void	isDuplicates(t_list **start);

void	printlist(t_list *current)
{
	while (current)
	{
		printf("%d -> ", *(int *)current->content);
		current = current->next;
	}
	printf("NULL\n");
}

void	printlistboth(t_list *stk_a, t_list *stk_b)
{
	ft_printf("Stack A: ");
	printlist(stk_a);
	ft_printf("Stack B: ");
	printlist(stk_b);
}

void	ft_free_int_content(void *content)
{
	free(content);
}

static int	free_split_array(char **array)
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

static int	populate_list_from_array(t_list **start, int count, char **array)
{
	int i;
	int *num_ptr;

	i = 0;
	while (i < count)
	{
		if (!is_valid_integer(array[i]))
		{
			ft_printf("Error\n");
			return (1);
		}
		num_ptr = malloc(sizeof(int));
		if (!num_ptr)
			return (1);
		*num_ptr = ft_atoi(array[i]);
		ft_lstadd_back(start, ft_lstnew(num_ptr));
		i++;
	}
	isDuplicates(start);
	return (0);
}
static void	isDuplicates(t_list **start)
{
	t_list	*inner_node;
	t_list	*outer_node;

	outer_node = *start;
	while (outer_node->next)
	{
		inner_node = outer_node->next;
		while (inner_node)
		{
			ft_printf("%d\n", *((int *)(outer_node->content)));
			if (*((int *)((outer_node)->content)) == (*((int *)(inner_node->content))))
				ft_printf("DUPLICATE\n");
			inner_node = inner_node->next;
		}
		outer_node = outer_node->next;
	}
}

static int	populate_from_single_string(t_list **start, char *arg_str)
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
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (argc == 2)
		return (populate_from_single_string(start, argv[1]));
	else
		return (populate_list_from_array(start, argc - 1, argv + 1));
}