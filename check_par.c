/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_par.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:59:13 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/09 22:45:55 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_parcinte(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_test(t_node **a)
{
	int		flag;
	int		count;
	t_node	*current;

	flag = 0;
	count = 0;
	current = *a;
	while (current != NULL && current->next != NULL)
	{
		count = current->content - current->next->content;
		if (count == 2 || count == 3 || count == 4)
			flag++;
		current = current->next;
	}
	if (flag >= 15 && flag < 99)
		return (0);
	return (1);
}
