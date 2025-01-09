/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_instractio_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:54:54 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/09 17:16:04 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bonus	*ft_lstnew_bonus(char *str)
{
	t_bonus	*new_node;

	new_node = malloc(sizeof(t_bonus));
	if (!new_node)
		return (NULL);
	new_node->rule = ft_strdup(str);
	new_node->more = NULL;
	return (new_node);
}

t_bonus	*ft_lstlast_bonus(t_bonus *lst)
{
	if (!lst)
		return (NULL);
	while (lst->more != NULL)
	{
		lst = lst->more;
	}
	return (lst);
}

void	ft_lstadd_back_bonus(t_bonus **lst, t_bonus *new)
{
	t_bonus	*node;

	if (!new)
		return ;
	node = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast_bonus(node);
	node->more = new;
}

void	first_instra_sa(t_node **a, t_bonus **ads)
{
	if (!ft_strcmp((*ads)->rule, "sa\n"))
		ft_swap_ar(a);
}

void	ft_create_instra(t_bonus **ads, t_node **a, t_node **b)
{
	while ((*ads) != NULL)
	{
		first_instra_sa(a, ads);
		if (!ft_strcmp((*ads)->rule, "sb\n"))
			ft_swap_ar(b);
		else if (!ft_strcmp((*ads)->rule, "ss\n"))
			ss(a, b);
		else if (!ft_strcmp((*ads)->rule, "pa\n"))
			push_ar(b, a, 3);
		else if (!ft_strcmp((*ads)->rule, "pb\n"))
			push_ar(a, b, 3);
		else if (!ft_strcmp((*ads)->rule, "ra\n"))
			ft_rotate(a, 3);
		else if (!ft_strcmp((*ads)->rule, "rb\n"))
			ft_rotate(b, 3);
		else if (!ft_strcmp((*ads)->rule, "rr\n"))
			rr(a, b, 3);
		else if (!ft_strcmp((*ads)->rule, "rra\n"))
			ft_reverse_rotate(a, 3);
		else if (!ft_strcmp((*ads)->rule, "rrb\n"))
			ft_reverse_rotate(b, 3);
		else if (!ft_strcmp((*ads)->rule, "rrr\n"))
			rrr(a, b, 3);
		(*ads) = (*ads)->more;
	}
}
