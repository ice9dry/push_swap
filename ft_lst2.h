/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:16:40 by marlee            #+#    #+#             */
/*   Updated: 2025/08/29 18:28:39 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST2_H
#define FT_LST2_H

#include <stdlib.h>
#include "struct.h"
#include "ft_lst1.h"

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_free_int_content(void *content);

#endif