#include "push_swap.h"

void ft_swap_ar(t_node **head)
{
    t_node *new;
    t_node *new1;
    t_node *current = NULL;
    
    current = *head;
    new = malloc(sizeof(t_node));
    if (new == NULL)
        return ;
    new1 = malloc(sizeof(t_node));
    if (new1 == NULL)
    {
        free(new);
        new = NULL;
        return ;
    }
    new->content = current->content;
    current = current->next;
    new1->content = current->content;
    current = *head;
    current->content = new1->content;
    current = current->next;
    current->content = new->content;
    free(new);
    free(new1);
}

void sa(t_node *a)
{
    ft_swap_ar(&a);
    write(1, "sa\n", 3);
}
