/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:47:27 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/04 16:53:03 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	not_sorted(t_node *a)
{
	t_node	*current;

	current = a;
	while (a != NULL)
	{
		current = current->next;
		if (current != NULL && a->content > current->content)
			return (0);
		a = a->next;
	}
	return (1);
}

t_node	*find_the_highest(t_node **a)
{
	t_node	*max_node;
	int		max;
	t_node	*current;

	current = *a;
	max = INT_MIN;
	max_node = NULL;
	while (current != NULL)
	{
		if (current->content > max)
		{
			max = current->content;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

void	sorted_way(t_node **a)
{
	t_node	*max_node;

	max_node = find_the_highest(a);
	if (*a == max_node)
		ft_rotate(a, 0);
	else if ((*a)->next == max_node)
		ft_reverse_rotate(a, 0);
	if ((*a)->content > (*a)->next->content)
		sa(*a);
}

void	push_swap(t_node **a, t_node **b)
{
	int	len_node;

	len_node = ft_lstsize(*a);
	if (ft_lstsize(*a) == 2)
		sa(*a);
	else if (ft_lstsize(*a) == 3)
		sorted_way(a);
	else if (len_node == 4)
		handler_four(a, b);
	else if (len_node == 5)
		handler_five(a, b);
	else
		ft_algorithm(a, b);
}
