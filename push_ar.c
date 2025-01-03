#include "push_swap.h"

int push_ar(t_node  **a, t_node **b)
{
    t_node *push = NULL;
    if (!a || !*a)
        return 1;
    push = *a;
    (*a)=(*a)->next;
    push->next = *b;
    *b = push;
    return 0;
}
