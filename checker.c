/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:15:09 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/06 00:09:15 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_p(t_node **a, t_node **b)
{
    ft_lstclear(a);
    ft_lstclear(b);
    write(1, "Error\n", 6);
    exit(1);
}

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 == *s2 && *s1)
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

void cammond(char *get_line, t_node **a, t_node **b)
{
    if (!ft_strcmp(get_line, "sa\n"))
        ft_swap_ar(a);
    else if (!ft_strcmp(get_line, "sb\n"))
        ft_swap_ar(b);
    else if (!ft_strcmp(get_line, "ss\n"))
        ss(a, b);
    else if (!ft_strcmp(get_line, "pa\n"))
        push_ar(b, a, 3);
    else if (!ft_strcmp(get_line, "pb\n"))
        push_ar(a, b, 3);
    else if (!ft_strcmp(get_line, "ra\n"))
        ft_rotate(a, 3);
    else if (!ft_strcmp(get_line, "rb\n"))
        ft_rotate(b, 3);
    else if (!ft_strcmp(get_line, "rr\n"))
        rr(a, b, 3);
    else if (!ft_strcmp(get_line, "rra\n"))
        ft_reverse_rotate(a, 3);
    else if (!ft_strcmp(get_line, "rrb\n"))
        ft_reverse_rotate(b, 3);
    else if (!ft_strcmp(get_line, "rrr\n"))
        rrr(a, b, 2);
    else
        error_p(a, b);
}

char **ft_fix_args(char **s, int ac)
{
    int i = 0;
    char **new;
    char *str = NULL;
    char *tmp;
    while (i < ac)
    {
        tmp = ft_strjoin1(str, s[i]);
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
    system("leaks checker");
}
int main(int ac, char *av[])
{
    atexit(sys);
    t_node *a = NULL;
    t_node *b = NULL;
    int len = 0;
    char *get_line;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return 1;
    if (ac == 2)
        av = ft_split(av[1], ' ');
    else
        av = ft_fix_args(av + 1, ac);
    a = create_list(av + 1, a);
    if (a == NULL)
    {
        write(1, "Error\n", 6);
        free_succ(a, av, ac);
        return 1;
    }
    len = ft_lstsize(a);
    get_line = get_next_line(0);
    while (get_line)
    {
        cammond(get_line, &a, &b);
        get_line = get_next_line(0);
    }
    if (not_sorted(a) && ft_lstsize(a) == len)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    b = a;
    while (b!=NULL)
    {
        printf("%d ", b->content);
        b=b->next;
    }
    free_succ(a, av, ac);
}
