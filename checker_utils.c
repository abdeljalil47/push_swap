/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:37:07 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/06 16:40:32 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_read(t_node *a, t_node *b, char **av, int ac)
{
	int		len;
	char	*get_line;
	int		i;

	i = 0;
	len = 0;
	while (i < ac)
	{
		free(av[i]);
		i++;
	}
	free(av);
	len = ft_lstsize(a);
	get_line = get_next_line(0);
	while (get_line)
	{
		cammond(get_line, &a, &b);
		free(get_line);
		get_line = get_next_line(0);
	}
	if (not_sorted(a) && ft_lstsize(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_succ1(a, b);
}

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (sign * result);
}

int	ft_lstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	not_sorted(t_node *a)
{
	t_node	*current;

	current = a;
	while (a != NULL)
	{
		current = current->next;
		if (current != NULL && a->content > current->content)
			return (0);
		a = a->next;
	}
	return (1);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*array;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	array = (char *)malloc((len1 + len2 + 2));
	if (array == NULL)
		return (NULL);
	ft_strlcpy(array, s1, len1 + 1);
	array[len1] = ' ';
	ft_strlcpy(array + len1 + 1, s2, len2 + 1);
	return (array);
}
