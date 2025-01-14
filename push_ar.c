/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:47:23 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/05 23:30:25 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_ar(t_node **a, t_node **b, int flag)
{
	t_node	*push;

	if (!a || !*a)
		return ;
	push = NULL;
	if (flag == 0)
		write(1, "pa\n", 3);
	else if (flag == 1)
		write(1, "pb\n", 3);
	push = *a;
	(*a) = (*a)->next;
	push->next = *b;
	*b = push;
}
