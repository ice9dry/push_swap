/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:10:09 by marlee            #+#    #+#             */
/*   Updated: 2025/09/02 08:31:08 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS1_H
# define UTILS1_H

#include "libft.h"

int		populate_list(t_list **start, int argc, char **argv);
void	printlist(t_list *current);
void	ft_free_int_content(void *content);

#endif