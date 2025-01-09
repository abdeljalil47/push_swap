/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:15:09 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/09 16:58:50 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_p(t_node **a, t_node **b, char *get_line)
{
	if (*a)
		ft_lstclear(a);
	if (*b)
		ft_lstclear(b);
	free(get_line);
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	cammond(char *get_line, t_node **a, t_node **b, t_bonus **ads)
{
	if (!ft_strcmp(get_line, "sa\n"))
		ft_lstadd_back_bonus(ads, ft_lstnew_bonus(get_line));
	else if (!ft_strcmp(get_line, "sb\n"))
		ft_lstadd_back_bonus(ads, ft_lstnew_bonus(get_line));
	else if (!ft_strcmp(get_line, "ss\n"))
		ft_lstadd_back_bonus(ads, ft_lstnew_bonus(get_line));
	else if (!ft_strcmp(get_line, "pa\n"))
		ft_lstadd_back_bonus(ads, ft_lstnew_bonus(get_line));
	else if (!ft_strcmp(get_line, "pb\n"))
		ft_lstadd_back_bonus(ads, ft_lstnew_bonus(get_line));
	else if (!ft_strcmp(get_line, "ra\n"))
		ft_lstadd_back_bonus(ads, ft_lstnew_bonus(get_line));
	else if (!ft_strcmp(get_line, "rb\n"))
		ft_lstadd_back_bonus(ads, ft_lstnew_bonus(get_line));
	else if (!ft_strcmp(get_line, "rr\n"))
		ft_lstadd_back_bonus(ads, ft_lstnew_bonus(get_line));
	else if (!ft_strcmp(get_line, "rra\n"))
		ft_lstadd_back_bonus(ads, ft_lstnew_bonus(get_line));
	else if (!ft_strcmp(get_line, "rrb\n"))
		ft_lstadd_back_bonus(ads, ft_lstnew_bonus(get_line));
	else if (!ft_strcmp(get_line, "rrr\n"))
		ft_lstadd_back_bonus(ads, ft_lstnew_bonus(get_line));
	else
		error_p(a, b, get_line);
}

char	**ft_fix_args(char **s, int ac)
{
	int		i;
	char	**new;
	char	*str;
	char	*tmp;

	i = 0;
	str = NULL;
	while (i < ac)
	{
		tmp = ft_strjoin1(str, s[i]);
		if (tmp == NULL)
			return (NULL);
		free(str);
		str = tmp;
		i++;
	}
	new = ft_split(str, ' ');
	if (new == NULL)
		return (NULL);
	free(str);
	return (new);
}

int	main(int ac, char *av[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (!ft_validarg(av, ac))
		return (write(1, "Error\n", 6), 1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av = ft_fix_args(av + 1, ac);
	a = create_list(av + 1, a);
	if (a == NULL)
	{
		write(1, "Error\n", 6);
		return ((free_succ(a, av)), 1);
	}
	checker_read(a, b, av, ac);
}
