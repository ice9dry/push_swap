/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_ops.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:44:55 by marlee            #+#    #+#             */
/*   Updated: 2025/09/01 12:53:53 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_OPS_H
# define FT_LST_OPS_H

#include "struct.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif