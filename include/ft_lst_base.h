/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_base.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:41:32 by marlee            #+#    #+#             */
/*   Updated: 2025/09/01 12:53:19 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_BASE_H
# define FT_LST_BASE_H

#include "struct.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_free_int_content(void *content);
t_list	*ft_lstlast(t_list *lst);

#endif