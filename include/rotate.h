/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:02:05 by marlee            #+#    #+#             */
/*   Updated: 2025/09/03 11:49:56 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATE_H
# define ROTATE_H

# include "libft.h"
# include "ft_printf.h"

void	rotate(t_list **stack);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stk_a, t_list **stk_b);

#endif