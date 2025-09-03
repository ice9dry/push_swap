/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:13:18 by marlee            #+#    #+#             */
/*   Updated: 2025/09/03 11:24:13 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_utils.h"

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
