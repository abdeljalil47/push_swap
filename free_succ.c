/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_succ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:38:22 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/06 14:47:34 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_succ(t_node *a, t_node *b, char **av, int ac)
{
	int	i;

	i = 0;
	while (*av && i < ac)
	{
		free(av[i]);
		i++;
	}
	free(av);
	ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
}

void	free_succ1(t_node *a, t_node *b)
{
	if (a)
		ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
}

t_node *error_free(t_node *a)
{
    if (a != NULL)
        ft_lstclear(&a);
    return (NULL);
}