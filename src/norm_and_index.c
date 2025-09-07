/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_and_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:52:14 by marlee            #+#    #+#             */
/*   Updated: 2025/09/07 22:15:35 by marlee           ###   ########.fr       */
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

int	norm_and_index(t_list *stk_a)
{
	int		*arr;
	int		i;
	t_list	*current;
	t_data	*data;

	arr = malloc(sizeof(int) * ft_lstsize(stk_a));
	if (!arr)
		return (1);
	current = stk_a;
	fill_tmp_array(current, arr);
	bubble_sort(arr, ft_lstsize(stk_a));
	current = stk_a;
	while (current)
	{
		data = (t_data *)current->content;
		data->index = get_sorted_index(data->value, arr, ft_lstsize(stk_a));
		current = current->next;
	}
	i = 0;
	while (i < ft_lstsize(stk_a))
		i++;
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
