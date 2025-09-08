/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:10:09 by marlee            #+#    #+#             */
/*   Updated: 2025/09/08 21:09:45 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTILS1_H
# define PARSE_UTILS1_H

# include "free_utils.h"
# include "parse_utils2.h"

typedef struct s_data
{
	int	value;
	int	index;
}	t_data;

int		check_and_populate(t_list **start, int argc, char **argv);

#endif