#include "push_swap.h"

int find_the_max(t_node **b)
{
    t_node *current = *b;
    int max = current->index;
    int max_pos = 0;
    int pos = 0;
    
    while (current != NULL)
    {
        if (current->index > max)
        {
            max = current->index;
            max_pos = pos;
        }
        current = current->next;
        pos++;
    }
    
    return max_pos;
}

void ft_sec_algorithm(t_node **a, t_node **b)
{
    int size = ft_lstsize(*b);
    int y = 0;

    while (size)
    {
        y = find_the_max(b);
        if (y <= size / 2)
        {
            while (y-- != 0)
                ft_rotate(b, 1);
        }
        else
        {
            while (y < size)
            {
                ft_reverse_rotate(b);
                write(1, "rrb\n", 4);
                y++;
            }
        }
        if (!push_ar(b, a))
            write(1, "pa\n", 3);
        size--;
    }
}
