/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:47:45 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/05 16:22:52 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **head, int flag)
{
	t_node	*current;
	t_node	*curr;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	current = NULL;
	curr = NULL;
	if (flag == 0)
		write(1, "ra\n", 3);
	else if (flag == 1)
		write(1, "rb\n", 3);
	else if (flag == 2)
		write(1, "rr\n", 3);
	current = *head;
	curr = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = *head;
	*head = (*head)->next;
	curr->next = NULL;
}

void rr(t_node **a, t_node **b, int flag)
{
	ft_rotate(a, flag);
	ft_rotate(b, 3);
}