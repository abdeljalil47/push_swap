#include "push_swap.h"

int set_index(t_node *min_node, int index)
{
    if (min_node)
    {
        min_node->index = index;
        min_node->flag = 1;
        index++;
    }
    return index;
}

void assign_indexes(t_node *head)
{
    t_node *current;
    t_node *min_node;
    int size = ft_lstsize(head);
    int index = 0;
    int min_value = 0;

    while (index < size)
    {
        current = head;
        min_node = NULL;
        min_value = INT_MAX;
        while (current != NULL)
        {
            if (current->flag == 0 && current->content <= min_value)
            {
                min_value = current->content;
                min_node = current;
            }
            current = current->next;
        }
        index = set_index(min_node, index);
    }
}

t_node *error_free(t_node *a)
{
    ft_lstclear(&a);
    return NULL;
}

t_node *create_list(char **s, t_node *a)
{
    int i = 0;
    long value = 0;
    int inndex = -1;
    int flag = 0;

    while (s[i] != NULL)
    {
        if (!check_argument(s[i]))
            return error_free(a);
        value = ft_atoi(s[i]);
        if (value > INT_MAX || value < INT_MIN)
            return error_free(a);
        if (!check_duplicate(a, (int)value))
            return error_free(a);
        ft_lstadd_back(&a, ft_lstnew((int)value, inndex, flag));
        i++;
    }
    assign_indexes(a);
    return (a);
}
