/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:10:09 by marlee            #+#    #+#             */
/*   Updated: 2025/09/02 16:42:35 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS1_H
# define UTILS1_H

#include "libft.h"

void	printlist(t_list *current);
void	ft_free_int_content(void *content);
int		check_and_populate(t_list **start, int argc, char **argv);
void	printlistboth(t_list *stk_a, t_list *stk_b);

#endif