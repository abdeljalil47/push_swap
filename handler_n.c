/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:38:30 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/04 16:45:42 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_the_smallest(t_node **a)
{
	t_node	*current;
	t_node	*min;
	int		i;
	int		index;

	current = *a;
	min = *a;
	i = 0;
	index = 0;
	if (*a == NULL)
		return (1);
	while (current != NULL)
	{
		if (current->content < min->content)
		{
			min = current;
			index = i;
		}
		current = current->next;
		i++;
	}
	return (index);
}

void	handler_four(t_node **a, t_node **b)
{
	t_node	*cur;
	int		min_node;

	min_node = find_the_smallest(a);
	cur = *a;
	if (min_node <= 2)
	{
		while (min_node-- != 0)
			ft_rotate(a, 0);
	}
	else
	{
		while (min_node++ != 4)
			ft_reverse_rotate(a, 0);
	}
	push_ar(a, b, 1);
	sorted_way(a);
	push_ar(b, a, 0);
}

void	handler_five(t_node **a, t_node **b)
{
	t_node	*cur;
	int		min_node;

	min_node = find_the_smallest(a);
	cur = *a;
	if (min_node <= 2)
	{
		while (min_node-- != 0)
			ft_rotate(a, 0);
	}
	else
	{
		while (min_node++ != 5)
			ft_reverse_rotate(a, 0);
	}
	push_ar(a, b, 1);
	handler_four(a, b);
	push_ar(b, a, 0);
}
