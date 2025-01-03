#include "push_swap.h"

int not_sorted(t_node *a)
{
    t_node *current = NULL;
    current = a;
    while (a != NULL)
    {
        current = current->next;
        if (current != NULL && a->content > current->content)
            return 0;
        a = a->next;
    }
    return 1;
}

t_node *find_the_highest(t_node **a)
{
    t_node *max_node = NULL;
    int max = INT_MIN;
    t_node *current = NULL;

    current = *a;
    while (current != NULL)
    {
        if (current->content > max)
        {
            max = current->content;
            max_node = current;
        }
        current = current->next;
    }
    return max_node;
}

void sorted_way(t_node **a)
{
    t_node *max_node = NULL;
    int max = INT_MIN;
    max_node = find_the_highest(a);
    if (*a == max_node)
        ft_rotate(a, 0);
    else if ((*a)->next == max_node)
    {
        ft_reverse_rotate(a);
        write(1, "rra\n", 4);
    }
    if ((*a)->content > (*a)->next->content)
        sa(*a);
}

void push_swap(t_node **a, t_node **b)
{
    int len_node = 0;
    len_node = ft_lstsize(*a);
    if (len_node == 5)
        handler_five(a, b);
    else if (len_node == 4)
        handler_four(a, b);
    else
        ft_algorithm(a, b);
}
