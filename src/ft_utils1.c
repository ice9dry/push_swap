/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:06:35 by marlee            #+#    #+#             */
/*   Updated: 2025/09/01 19:05:43 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_utils1.h"
#include "ft_lst_ops.h"
#include "ft_lst_base.h"

static int	ft_changesign(int character)
{
	if (character == '-')
		return (-1);
	else if (character == '+')
		return (1);
	else
		return (0);
}

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = ft_changesign(str[i]);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
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

void	printlist(t_list *current)
{
	while (current)
	{
		printf("%d -> ", *(int *)current->content);
		current = current->next;
	}
	printf("NULL\n");
}