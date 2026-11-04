/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_and_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marklee <marklee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:52:14 by marlee            #+#    #+#             */
/*   Updated: 2026/11/04 21:43:33 by marklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norm_and_index.h"

void	fill_tmp_array(t_list *current, int *arr)
{
	int		i;
	t_data	*data;

	i = 0;
	while (current)
	{
		data = (t_data *)current->content;
		arr[i] = data->value;
		i++;
		current = current->next;
	}
}

// Function attaches an index number against the value
// e.g. If the values are 1, 10, 5 then, the index would be 1, 3, 2
// This is so the sorting algo would be comparing the index instead of the values
// Important for Radix sort which uses bit shifting comparison
// Returns 0 for no errors
// Returns 1 when there is a malloc error (for the temp array)
int	norm_and_index(t_list *stk_a)
{
	int		*arr;
	t_list	*current;
	t_data	*data;

	arr = malloc(sizeof(int) * ft_lstsize(stk_a));
	if (!arr)
		return (1);
	current = stk_a;
	fill_tmp_array(current, arr);
	bubble_sort(arr, ft_lstsize(stk_a));
	current = stk_a; // Extra line below which prob can remove
	while (current)
	{
		data = (t_data *)current->content;
		data->index = get_sorted_index(data->value, arr, ft_lstsize(stk_a));
		current = current->next;
	}
	free(arr);
	return (0);
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	get_sorted_index(int value, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (value == arr[i])
			return (i);
		i++;
	}
	return (-1);
}
