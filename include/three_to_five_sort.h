/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_to_five_sort.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:39:06 by marlee            #+#    #+#             */
/*   Updated: 2025/09/08 19:17:18 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREE_TO_FIVE_SORT_H
# define THREE_TO_FIVE_SORT_H

# include "libft.h"
# include "ft_printf.h"
# include "parse_utils1.h"
# include "push.h"
# include "rotate.h"
# include "reverse_rotate.h"
# include "swap.h"

void	three_sort(t_list **stk_a);
void	four_sort(t_list **stk_a, t_list **stk_b);
void	five_sort(t_list **stk_a, t_list **stk_b);

#endif