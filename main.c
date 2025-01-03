#include "push_swap.h"

char **ft_fix_arg(char **s, int ac)
{
    int i = 0;
    char *str = NULL;
    char **new;
    char *tmp;

    while (i < ac)
    {
        tmp = ft_strjoin(str, s[i]);
        free(str);
        str = tmp;
        i++;
    }
    new = ft_split(str, ' ');
    free(str);
    return new;
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
    free(av);
    if (a == NULL)
    {
        printf("Error\n");
        return 1;
    }
    if (!not_sorted(a))
    {
        if (ft_lstsize(a) == 2)
            sa(a);
        else if (ft_lstsize(a) == 3)
            sorted_way(&a);
        else
            push_swap(&a, &b);
    }
    b = a;
    while (b!=NULL)
    {
        printf("%d ", b->content);
        b = b->next;
    }
    ft_lstclear(&a);
    return 0;
}
