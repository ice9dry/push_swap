/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:06:35 by marlee            #+#    #+#             */
/*   Updated: 2025/09/03 19:43:55 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils1.h"

static int	check_duplicates(t_list **start)
{
	t_list	*inner_node;
	t_list	*outer_node;

	outer_node = *start;
	while (outer_node->next)
	{
		inner_node = outer_node->next;
		while (inner_node)
		{
			// ft_printf("%d\n", *((int *)(outer_node->content)));
			if (((t_data *)outer_node->content)->value \
== (((t_data *)inner_node->content)->value))
			{
				ft_printf("DUPLICATE\n");
				return (1);
			}
			inner_node = inner_node->next;
		}
		outer_node = outer_node->next;
	}
	return (0);
}

static int	populate_list_from_array(t_list **start, int count, char **array)
{
	int		i;
	// int		*num_ptr;
	t_data	*data;

	i = 0;
	while (i < count)
	{
		if (!is_valid_integer(array[i]))
		{
			ft_printf("Error\n");
			return (1);
		}
		data = malloc(sizeof(t_data));
		if (!data)
			return (1);
		data->value = ft_atoi(array[i]);
		ft_lstadd_back(start, ft_lstnew(data));
		i++;
	}
	if (check_duplicates(start))
		return (1);
	return (0);
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
