#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// typedef struct push_swap
// {
//     int content;
//     int index;
//     int flag;
//     struct push_swap *next;
// } t_node;

// t_node    *ft_lstnew(int content)
// {
//     t_node    *node;

//     node = (t_node *)malloc(sizeof(t_node));
//     if (node == NULL)
//         return (NULL);
//     node->content = content;
//     node->next = NULL;
//     return (node);
// }

// t_node    *ft_lstlast(t_node *lst)
// {
//     if (!lst)
//         return (NULL);
//     while (lst->next != NULL)
//     {
//         lst = lst->next;
//     }
//     return (lst);
// }

// void    ft_lstadd_back(t_node **lst, t_node *new)
// {
//     t_node    *node;

//     if (!new)
//         return ;
//     node = *lst;
//     if (*lst == NULL)
//     {
//         *lst = new;
//         new->flag = 0;
//         new->next = NULL;
//         return ;
//     }
//     node = ft_lstlast(node);
//     node->next = new;
//     new->flag = 0;
// }
// int    ft_lstsize(t_node *lst)
// {
//     int    i;

//     i = 0;
//     if (!lst)
//         return (0);
//     while (lst)
//     {
//         i++;
//         lst = lst->next;
//     }
//     return (i);
// }
// void check(t_node *current, t_node *head)
// {
//     unsigned int i = 0;
//     unsigned int j = 0;
//     unsigned int value = 0;
//     t_node *prev = NULL;
//     int size = ft_lstsize(head);
    
//     value = current->content;
//     while (current != NULL)
//     {
//         if (value > current->content && current->flag == 0)
//         {
//             value = current->content;
//             prev = current;
//         }
//         current = current->next;
//     }
//     current = head;
//     if (current->flag == 0)
//     {
//       prev->index = j;
//       prev->flag = 1;
//       j++;
//     }
//     if (i < size)
//     {
//       check(current, head);
//     }
//     printf("%d\n", value);
//     printf("%d\n", prev->content);
// }
// void create_list(char **s)
// {
//     t_node *head = NULL;
//     t_node *current = NULL;

//     unsigned int i = 0;
//     unsigned int value = 0;
//     while (s[i] != NULL)
//     {
//         value = atoi(s[i]);
//         ft_lstadd_back(&head, ft_lstnew(value));
//         i++;
//     }
//     current = head;
//     check(current, head);
//     while (current != NULL)
//     {
//         printf("%d\n", current->content);
//         current = current->next;
//     }
// }

// int main()
// {
//     char *av[] = {"6", "4", "8", "1", "2",NULL};
//     create_list(av);
//     return 0;
// }

// int binary_search(int arr[], int size, int target) {
//     int low = 0;
//     int high = size - 1;

//     while (low <= high) {
//         int mid = (low + high) / 2;
        
//         if (arr[mid] == target)
//             return mid;
//         else if (arr[mid] < target)
//             low = mid + 1;
//         else
//             high = mid - 1;
//     }

//     return -1;
// }

// int main()
// {
//     int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int target = 7;

//     int result = binary_search(arr, size, target);

//     if (result != -1) {
//         printf("Element %d found at index %d.\n", target, result);
//     } else {
//         printf("Element %d not found.\n", target);
//     }

//     return 0;
// }
12 492 86 315 77 239 91 654 8 221 532 100 321 564 13 71 890 457 84 342 109 657 23 410 55 789 212 144 38 693 269 567 486 17 99 476 205 733 512 412 681 74 15 950 305 21 568 128 673 64 287 19 316 847 35 784 509 190 432 21 876 342 987 533 453 609 818 194 123 803 45 76 190 348 561 662 504 14 265 592 888 475 341 902 758 973 221 324 11 420 298 114 582 30 739 466 309 28 849 273