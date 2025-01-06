/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:38:37 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/06 15:06:08 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_fix_arg(char **s, int ac)
{
	int		i;
	char	*str;
	char	**new;
	char	*tmp;

	i = 0;
	str = NULL;
	while (i < ac)
	{
		tmp = ft_strjoin1(str, s[i]);
		free(str);
		str = tmp;
		i++;
	}
	new = ft_split(str, ' ');
	free(str);
	return (new);
}
void sys()
{
	system("leaks push_swap");
}
int	main(int ac, char *av[])
{
	atexit(sys);
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av = ft_fix_arg(av + 1, ac);
	a = create_list(av + 1, a);
	if (a == NULL)
	{
		write(1, "Error\n", 6);
		return (free_succ(a, b, av, ac), 1);
	}
	if (!not_sorted(a))
		push_swap(&a, &b);
	b = a;
	while (b!=NULL)
	{
		printf("%d ", b->content);
		b=b->next;
	}
	free_succ(a, b, av, ac);
	return (0);
}
