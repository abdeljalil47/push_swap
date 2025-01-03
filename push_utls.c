#include "push_swap.h"

t_node *ft_lstnew(int content, int index, int flag)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (node == NULL)
        return (NULL);
    node->content = content;
    node->index = index;
    node->flag = flag;
    node->next = NULL;
    return (node);
}

t_node *ft_lstlast(t_node *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next != NULL)
    {
        lst = lst->next;
    }
    return (lst);
}

void ft_lstadd_back(t_node **lst, t_node *new)
{
    t_node *node;

    if (!new)
        return;
    node = *lst;
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    node = ft_lstlast(node);
    node->next = new;
}

int ft_lstsize(t_node *lst)
{
    int i = 0;

    while (lst)
    {
        i++;
        lst = lst->next;
    }
    return (i);
}

void	ft_lstclear(t_node **lst)
{
	t_node	*move_node;
	t_node	*node;

	if (!lst)
		return ;
	node = *lst;
	while (node)
	{
		move_node = node->next;
		free(node);
		node = move_node;
	}
	*lst = NULL;
}

long ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    long result = 0;

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
    return sign * result;
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

char	*ft_strdup(const char *s)
{
	char	*array;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	array = (char *)malloc((len + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	while (s[i])
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*ft_strjoin(char *s1, char *s2)
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
