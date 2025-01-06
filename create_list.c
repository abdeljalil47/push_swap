/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:38:17 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/07 00:24:27 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_index(t_node *min_node, int index)
{
	if (min_node)
	{
		min_node->index = index;
		min_node->flag = 1;
		index++;
	}
	return (index);
}

void	assign_indexes(t_node *head)
{
	t_node	*current;
	t_node	*min_node;
	int		size;
	int		index;
	int		min_value;

	size = ft_lstsize(head);
	index = 0;
	min_value = 0;
	while (index < size)
	{
		current = head;
		min_node = NULL;
		min_value = INT_MAX;
		while (current != NULL)
		{
			if (current->flag == 0 && current->content <= min_value)
			{
				min_value = current->content;
				min_node = current;
			}
			current = current->next;
		}
		index = set_index(min_node, index);
	}
}

t_node	*create_list(char **s, t_node *a)
{
	int		i;
	long	value;
	int		inndex;
	int		flag;

	i = 0;
	value = 0;
	inndex = -1;
	flag = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != NULL)
	{
		if (!check_argument(s[i]))
			return (error_free(a));
		value = ft_atoi(s[i]);
		if (value > INT_MAX || value < INT_MIN)
			return (error_free(a));
		if (!check_duplicate(a, (int)value))
			return (error_free(a));
		ft_lstadd_back(&a, ft_lstnew((int)value, inndex, flag));
		i++;
	}
	assign_indexes(a);
	return (a);
}
