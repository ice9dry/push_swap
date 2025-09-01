/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:10:09 by marlee            #+#    #+#             */
/*   Updated: 2025/09/01 20:45:49 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS1_H
# define UTILS1_H

#include "libft.h"

int		ft_atoi(const char *str);
int		populate_list(t_list **start, int argc, char **argv);
void	printlist(t_list *current);

#endif