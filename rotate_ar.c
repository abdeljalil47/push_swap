#include "push_swap.h"

int ft_rotate(t_node **head, int flag)
{
    t_node *current = NULL;
    t_node *curr = NULL;
    if (*head == NULL || (*head)->next == NULL)
        return 1;
    if (flag == 0)
        write(1, "ra\n", 3);
    else if (flag == 1)
        write(1, "rb\n", 3);
    current = *head;
    curr = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = *head;
    *head = (*head)->next;
    curr->next = NULL;
    return 0;
}
