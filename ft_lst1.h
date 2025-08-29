/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:15:21 by marlee            #+#    #+#             */
/*   Updated: 2025/08/29 14:39:40 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST1_H
#define FT_LST1_H

#include <stdlib.h>
#include "struct.h"
#include "ft_lst2.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

#endif