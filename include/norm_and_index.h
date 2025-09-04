/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_and_index.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:59:48 by marlee            #+#    #+#             */
/*   Updated: 2025/09/04 22:28:32 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORM_AND_INDEX_H
# define NORM_AND_INDEX_H

# include "libft.h"
# include "ft_printf.h"
# include "parse_utils1.h"

void	bubble_sort(int *arr, int size);
int		get_sorted_index(int value, int *arr, int size);
int	norm_and_index(t_list *stk_a);

#endif