/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_succ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:38:22 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/06 16:39:34 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_succ(t_node *a, char **av)
{
	int	i;

	i = 0;
	ft_lstclear(&a);
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	free_succ1(t_node *a, t_node *b)
{
	if (a)
		ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
}

t_node	*error_free(t_node *a)
{
	ft_lstclear(&a);
	return (NULL);
}
