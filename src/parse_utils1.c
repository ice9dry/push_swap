/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:06:35 by marlee            #+#    #+#             */
/*   Updated: 2025/09/12 16:32:37 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils1.h"

static int	populate_from_single_string(t_list **start, char *arg_str);

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
			if (((t_data *)outer_node->content)->value
				== (((t_data *)inner_node->content)->value))
				return (1);
			inner_node = inner_node->next;
		}
		outer_node = outer_node->next;
	}
	return (0);
}

static int	fill_data_cell(t_list **start, char *array)
{
	t_data		*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->value = ft_atoi(array);
	ft_lstadd_back(start, ft_lstnew(data));
	return (0);
}

static int	populate_list_from_array(t_list **start, int count, char **array)
{
	int		i;

	i = 0;
	while (i < count)
	{
		if (ft_strchr(array[i], ' ') != NULL)
		{
			if (populate_from_single_string(start, array[i]))
				return (1);
		}
		else
		{
			if (!is_valid_integer(array[i]))
				return (1);
			fill_data_cell(start, array[i]);
		}
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
	if (count == 0)
	{
		free_split_array(split_array);
		return (1);
	}
	status = populate_list_from_array(start, count, split_array);
	free_split_array(split_array);
	return (status);
}

int	check_and_populate(t_list **start, int argc, char **argv)
{
	if (argc < 2)
		return (3);
	if (argc == 2 && argv[1][0] == '\0')
		return (2);
	if (argc == 2)
		return (populate_from_single_string(start, argv[1]));
	else
		return (populate_list_from_array(start, argc - 1, argv + 1));
}
