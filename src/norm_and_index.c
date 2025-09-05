/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_and_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:52:14 by marlee            #+#    #+#             */
/*   Updated: 2025/09/05 21:31:28 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norm_and_index.h"

int	norm_and_index(t_list *stk_a)
{
	int		*arr;
	t_list	*current;
	t_data	*data;

	arr = malloc(sizeof(int) * ft_lstsize(stk_a));
	if (!arr)
		return (1);
	current = stk_a;
	int i = 0;
	while (current)
	{
		data = (t_data *)current->content;
		arr[i] = data->value;
		// ft_printf("%d -> ",arr[i]);
		i++;
		current = current->next;
	}
	// ft_printf("lstsize = %d\n", ft_lstsize(stk_a));
	ft_printf("Bubble sort start\n");
	bubble_sort(arr, ft_lstsize(stk_a));
	ft_printf("Bubble sort end\n");
	current = stk_a;
	while (current)
	{
		data = (t_data *)current->content;
		data->index = get_sorted_index(data->value, arr, ft_lstsize(stk_a));
		// ft_printf("%d (%d) -> ", data->value, data->index);
		current = current->next;
	}
	// ft_printf("\n");
	i = 0;
	while (i < ft_lstsize(stk_a))
	{
		// ft_printf("%d -> ", arr[i]);
		i++;
	}
	// ft_printf("\n");
	free(arr);
	return (0);
}

void bubble_sort(int *arr, int size)
{
	int i;
	int j;
	int temp;

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
int		get_sorted_index(int value, int *arr, int size)
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