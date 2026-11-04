/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marklee <marklee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:06:35 by marlee            #+#    #+#             */
/*   Updated: 2026/11/04 21:17:22 by marklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils1.h"

static int	populate_from_single_string(t_list **start, char *arg_str);

// Function checks for dups in the linked list
// Returns 0 if not dups, or error 1 if there are dups
static int	check_duplicates(t_list *start)
{
	t_list	*inner_node;
	t_list	*outer_node;

	outer_node = start;
	while (outer_node->next)
	{
		inner_node = outer_node->next;
		while (inner_node)
		{
			if (((t_data *)outer_node->content)->value
				== (((t_data *)inner_node->content)->value))
				return (1);
			inner_node = inner_node->next;
		}
		outer_node = outer_node->next;
	}
	return (0);
}

static int	fill_data_cell(t_list **start, char *array)
{
	t_data		*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->value = ft_atoi(array);
	ft_lstadd_back(start, ft_lstnew(data));
	return (0);
}
// Function parses the array of characters
// (could be numbers or letters at this point)
// if it is not a number, return with error 1
static int	populate_list_from_array(t_list **start, int count, char **array)
{
	int		i;

	i = 0;
	while (i < count)
	{
		// check if the element has a space
		if (ft_strchr(array[i], ' ') != NULL)
		{
			// if there is a space, then assume it is a string
			// with more than one element
			// then parse the string to extract the elements
			// in the string into the linked list
			// Note: the function below actually calls this function
			// again, but will not go into this loop since it
			// will be a single element
			if (populate_from_single_string(start, array[i]))
				// if there is an error, e.g. the string is empty
				// then return an error of 1
				return (1);
		}
		// else if it is a single element check if the it is an integer
		else
		{
			// check if the character(s) is an integer
			if (!is_valid_integer(array[i]))
				// if not an integer, return error 1
				return (1);
			// finally if all is okay, put the integer into the linked list
			fill_data_cell(start, array[i]);
		}
		i++;
	}
	// check if there are dups.
	if (check_duplicates(*start))
		// if there are, return error with 1
		return (1);
	return (0);
}

// Function splits numbers in the string and
// returns 0 for no error, 1 for error.
static int	populate_from_single_string(t_list **start, char *arg_str)
{
	char	**split_array;
	int		count;
	int		status;

	split_array = ft_split(arg_str, ' ');
	if (!split_array)
		return (1);
	count = 0;
	while (split_array[count])
		count++;
	// if there are no numbers inside, e.g. " ", then
	// free what was malloc'ed and return with error 1
	if (count == 0)
	{
		free_split_array(split_array);
		return (1);
	}
	// if the string has characters the populate the linked list
	status = populate_list_from_array(start, count, split_array);
	free_split_array(split_array);
	return (status);
}

// Function tries to populate the linked list
// Returns 0 if everything is okay
// Returns 1 if there are parameters but the parsing has errors e.g. non-integer
// Returns 2 if there is a string as parameter but the string is empty i.e. ""
// Returns 3 if there are no parameters
int	check_and_populate(t_list **start, int argc, char **argv)
{
	// if there are no parameters, return with error 3
	if (argc <= 1)
		return (3);
	// if there is only 1 parameter, but it is empty, return with error 2
	if (argc == 2 && argv[1][0] == '\0')
		return (2);
	// if there is 1 parameter with characters in it,
	// start population as a string
	if (argc == 2)
		return (populate_from_single_string(start, argv[1]));
	else
	// else if it is multi parameter, i.e. array, then do this
		return (populate_list_from_array(start, argc - 1, argv + 1));
}
