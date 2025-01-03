#include "push_swap.h"

void ft_algorithm(t_node **a, t_node **b)
{
    int i = 0;
    int size;
    int range;
    t_node *current = NULL;
    size = ft_lstsize(*a);
    if (size > 100)
        range = 33;
    else
        range = 16;
    current = *a;
    while (current != NULL)
    {
        if (current->index <= i)
        {
            if (!push_ar(a, b))
                write(1, "pb\n", 3);
            i++;
        }
        else if (current->index <= (i + range))
        {
            if (!push_ar(a, b))
                write(1, "pb\n", 3);
            ft_rotate(b, 1);
            i++;
        }
        else // check this case 100 98 96 94 92 90 88 86 84 82 80 78 76 74 72 70 68 66 64 62 60 58 56 54 52 50 48 46 44 42 40 38 36 34 32 30 28 26 24 22 20 18 16 14 12 10 8 6 4 2
        //99 97 95 93 91 89 87 85 83 81 79 77 75 73 71 69 67 65 63 61 59 57 55 53 51 49 47 45 43 41 39 37 35 33 31 29 27 25 23 21 19 17 15 13 11 9 7 5 3 1-> then make reverse_rotate.
        {
            ft_rotate(a, 0);
        }    
        current = *a;
    }
    ft_sec_algorithm(a, b);
}
