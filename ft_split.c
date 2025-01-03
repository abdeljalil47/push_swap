#include "push_swap.h"

size_t ft_count_word(const char *str, char c)
{
    size_t i = 0;
    size_t count = 0;
    int token = 1;
    while (str[i])
    {
        if (str[i] == c)
            token = 1;
        else
        {
            if (token == 1)
            {
                count++;
                token = 0;
            }
        }
        i++;
    }
    return count;
}

int ft_safe_malloc(size_t len, int pos, char **strings)
{
    unsigned int i = 0;
    strings[pos] = malloc(len + 1);
    if (strings[pos] == NULL)
    {
        while (i < pos)
        {
            free(strings[i]);
            i++;
        }
        free(strings);
        return 1;
    }
    return 0;
}

int ft_fill_string(const char *s, char c, char **strings)
{
    size_t j = 0;
    size_t len = 0;
    while (*s)
    {
        len = 0;
        while (*s == c && *s)
            s++;
        while (*s != c && *s)
        {
            len++;
            s++;
        }
        if (len > 0)
        {
            if (ft_safe_malloc(len, j, strings))
                return 1;
            ft_strlcpy(strings[j], s - len, len + 1);
            j++;
        }
    }
    return 0;
}

char **ft_split(const char *s, char c)
{
    size_t count_word = 0;
    char **strings;

    if (s == NULL)
        return NULL;
    count_word = ft_count_word(s, c);
    strings = malloc((count_word + 2) * sizeof(char *));
    if (strings == NULL)
        return NULL;
    strings[0] = malloc(sizeof(char));
    if (strings[0] == NULL)
        return NULL;
    strings[0][0] = '\0';
    strings[count_word + 1] = NULL;
    if (ft_fill_string(s, c, strings + 1))
        return NULL;
    return strings;
}
