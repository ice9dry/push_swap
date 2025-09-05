/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:24:22 by marlee            #+#    #+#             */
/*   Updated: 2025/09/05 18:54:36 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHOOSE_SORT_H
# define CHOOSE_SORT_H

# include "libft.h"
# include "ft_printf.h"
# include "parse_utils1.h"
# include "radix_sort.h"
# include "three_sort.h"
# include "chunk_sort.h"

void	choose_sort(t_list **stk_a, t_list **stk_b);

#endif