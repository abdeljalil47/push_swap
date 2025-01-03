#include "push_swap.h"

int ft_isdigit(int c) // for digit
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int ft_sign(int c) // for sign + -
{
    if (c == '-' || c == '+')
        return (1);
    return (0);
}

int check_duplicate(t_node *a, int nb)
{
    while (a != NULL)
    {
        if (a->content == nb)
            return 0;
        a = a->next;
    }
    return 1;
}

int check_argument(char *av)
{
    int i = 0;

    if (av[i] == '\0')
        return 0;
    while (av[i])
    {
        if (!(ft_sign(av[i]) || ft_isdigit(av[i])))
            return 0;
        else if (ft_sign(av[i]) && !ft_isdigit(av[i + 1]))
            return 0;
        i++;
    }
    return 1;
}
