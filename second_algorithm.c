/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:47:51 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/04 16:47:51 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_the_max(t_node **b)
{
	t_node	*current;
	int		max;
	int		max_pos;
	int		pos;

	current = *b;
	max = current->index;
	max_pos = 0;
	pos = 0;
	while (current != NULL)
	{
		if (current->index > max)
		{
			max = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

void	ft_sec_algorithm(t_node **a, t_node **b)
{
	int	size;
	int	y;

	size = ft_lstsize(*b);
	y = 0;
	while (size)
	{
		y = find_the_max(b);
		if (y <= size / 2)
		{
			while (y-- != 0)
				ft_rotate(b, 1);
		}
		else
		{
			while (y < size)
			{
				ft_reverse_rotate(b, 1);
				y++;
			}
		}
		push_ar(b, a, 0);
		size--;
	}
}
