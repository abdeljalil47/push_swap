/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:47:41 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/07 15:48:49 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_node **head, int flag)
{
	t_node	*current;
	t_node	*prev;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	current = *head;
	prev = NULL;
	if (flag == 0)
		write(1, "rra\n", 4);
	else if (flag == 1)
		write(1, "rrb\n", 4);
	else if (flag == 2)
		write(1, "rrr\n", 3);
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	current->next = *head;
	*head = current;
	prev->next = NULL;
}

void	rrr(t_node **a, t_node **b, int flag)
{
	ft_reverse_rotate(a, flag);
	ft_reverse_rotate(b, 3);
}
