#include "push_swap.h"

char **ft_fix_arg(char **s, int ac)
{
    int i = 0;
    char *str = NULL;
    while (i < ac)
    {
        str = ft_strjoin(str, s[i]);
        i++;
    }
    s = ft_split(str, ' ');
    return s;
}

void sys()
{
    system("leaks a.out");
}

int main(int ac, char *av[])
{
    atexit(sys);
    t_node *a = NULL;
    t_node *b = NULL;
    int i = 0;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return 1;
    if (ac == 2)
        av = ft_split(av[1], ' ');
    else
        av = ft_fix_arg(av + 1, ac);
    a = create_list(av + 1, a);
    while (i < ac)
    {
        free(av[i]);
        i++;
    }
    if (a == NULL)
    {
        printf("Error\n");
        return 1;
    }
    if (!not_sorted(a)) // not sorted
    {
        if (ft_lstsize(a) == 2)
            sa(a);
        else if (ft_lstsize(a) == 3)
            sorted_way(&a); // need to creat function to dale with 3 arg
        else
            push_swap(&a, &b); // need to creat function to dale with 4 and 5 arg
    }
    while (a != NULL)
    {
        printf("%d ", a->content);
        a = a->next;
    }
    ft_lstclear(&a);
    return 0;
}
