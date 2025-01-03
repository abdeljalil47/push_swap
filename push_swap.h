#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <libc.h>
#include <limits.h>

typedef struct push_swap
{
    int content;
    int index;
    int flag;
    struct push_swap *next;
} t_node;

void    push_swap(t_node **a, t_node **b);
int     check_argument(char *av);
int     check_duplicate(t_node *a, int nb);
char    **ft_split(const char *s, char c);
size_t  ft_strlen(const char *str);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
t_node  *create_list(char **s, t_node *a);
long    ft_atoi(char *str);
void    ft_algorithm(t_node **head, t_node **b);
void    ft_sec_algorithm(t_node **a, t_node **b);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
int     not_sorted(t_node *a);
void    sorted_way(t_node **a);
t_node *find_the_highest(t_node **a);
void    handler_four(t_node **a, t_node **b);
void    handler_five(t_node **a, t_node **b);

int     push_ar(t_node  **a, t_node **b);
int    ft_reverse_rotate(t_node **head);
int     ft_rotate(t_node **head, int flag);
void    ft_swap_ar(t_node **head);
void    sa(t_node *a);

t_node  *ft_lstnew(int content, int index, int flag);
t_node  *ft_lstlast(t_node *lst);
void    ft_lstadd_back(t_node **lst, t_node *new);
int     ft_lstsize(t_node *lst);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstclear(t_node **lst);

#endif