/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:38:20 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/08 21:43:18 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_range(t_node **a)
{
	int	range;
	int	size;

	size = ft_lstsize(*a);
	if (size > 100)
		return (range = 33);
	else
		return (range = 16);
}

void	ft_algorithm(t_node **a, t_node **b)
{
	int		i;
	int		range;
	t_node	*current;

	current = *a;
	range = check_range(a);
	i = 0;
	while (current != NULL)
	{
		if (current->index <= i)
		{
			push_ar(a, b, 1);
			i++;
		}
		else if (current->index <= (i + range))
		{
			push_ar(a, b, 1);
			ft_rotate(b, 1);
			i++;
		}
		else
			ft_rotate(a, 0);
			// ft_reverse_rotate(a, 0);
		current = *a;
	}
	ft_sec_algorithm(a, b);
}
