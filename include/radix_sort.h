/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:23:08 by marlee            #+#    #+#             */
/*   Updated: 2025/09/05 11:07:48 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIX_SORT_H
# define RADIX_SORT_H

# include "libft.h"
# include "parse_utils1.h"
# include "push.h"
# include "rotate.h"
# include "reverse_rotate.h"
# include "swap.h"
# include "printout_utils.h"

void	radix_sort(t_list **stk_a, t_list **stk_b);
void	radix_sort_2(t_list **stk_a, t_list **stk_b);

#endif