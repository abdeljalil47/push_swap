#include "push_swap.h"

int find_the_smallest(t_node **a)
{
    t_node *current = *a;
    t_node *min = *a;
    int i = 0;
    int index = 0;
    if (*a == NULL)
        return 1;
    while (current != NULL)
    {
        if (current->content < min->content)
        {
            min = current;
            index = i;
        }
        current = current->next;
        i++;
    }
    return index;
}

void handler_four(t_node **a, t_node **b)
{
    t_node *cur = NULL;
    int min_node = find_the_smallest(a);
    cur = *a;
    if (min_node <= 2)
    {
        while (min_node-- != 0)
            ft_rotate(a, 0);
    }
    else
    {
        while (min_node++ != 4)
        {
            ft_reverse_rotate(a);
            write(1, "rra\n", 4);
        }
    }
    if (!push_ar(a, b))
        write(1, "pb\n", 3);
    sorted_way(a);
    if (!push_ar(b, a))
        write(1, "pa\n", 3);
}

void    handler_five(t_node **a, t_node **b)
{
    t_node *cur = NULL;
    int min_node = find_the_smallest(a);
    cur = *a;
    if (min_node <= 2)
    {
        while (min_node-- != 0)
            ft_rotate(a, 0);
    }
    else
    {
        while (min_node++ != 5)
        {
            ft_reverse_rotate(a);
            write(1, "rra\n", 4);
        }
    }
    if (!push_ar(a, b))
        write(1, "pb\n", 3);
    handler_four(a, b);
    if (!push_ar(b, a))
        write(1, "pa\n", 3);
}
