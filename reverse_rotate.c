#include "push_swap.h"

int ft_reverse_rotate(t_node **head)
{
    t_node *current = *head;
    t_node *prev = NULL;
    if (*head == NULL || (*head)->next == NULL)
        return 1;
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    current->next = *head;
    *head = current;
    prev->next = NULL;
    return 0;
}
