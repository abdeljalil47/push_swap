/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_succ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:38:22 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/10 16:19:40 by abdsebba         ###   ########.fr       */
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

void	ft_lstfree_bonus(t_bonus *node)
{
	if (node)
	{
		if (node->rule)
			free(node->rule);
		free(node);
	}
}

void	ft_lstclear1(t_bonus **lst)
{
	t_bonus	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->more;
		ft_lstfree_bonus(temp);
	}
}

void	free_succ1(t_node *a, t_node *b, t_bonus *ads)
{
	if (a)
		ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
	if (ads)
		ft_lstclear1(&ads);
}

t_node	*error_free(t_node *a)
{
	ft_lstclear(&a);
	return (NULL);
}
