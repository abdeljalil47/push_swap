/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:47:54 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/05 23:26:33 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap_ar(t_node **head)
{
    t_node *first;
    t_node *second;
	int temp;

    if (*head == NULL || (*head)->next == NULL)
        return ;
    first = *head;
    second = first->next;
    temp = first->content;
    first->content = second->content;
    second->content = temp;
}


void	sa(t_node *a)
{
	ft_swap_ar(&a);
	write(1, "sa\n", 3);
}

void	sb(t_node *b)
{
	ft_swap_ar(&b);
	write(1, "sb\n", 3);
}

void ss(t_node **a, t_node **b)
{
	ft_swap_ar(a);
	ft_swap_ar(b);
}