#include "ft_printf.h"

int     ft_len_num(int d)
{
    int i;

    i = 0;
    if (d < 0)
    {
        i = 1;
        d = d * (-1);
    }
    while (d > 0)
    {
        d = d / 10;
        i++;
    }
    return (i);
}

char    *ft_after_d(char *d, t_forme list)
{
    char *tab;
    char *str;
    int i;
    int n;

    i = 0;
    if (ft_strsearch(list.size, '-') == 1)
    {
        tab = (char *)malloc(sizeof(char) * list.width);
        tab = d;
        n = list.width - ft_strlen(d);
        while (n > 0)
        {
            i++;
            tab[i] = ' ';
            n--;
        }
        tab[list.width] = '\0';
    }
    return (tab);
}

char *ft_type_int(va_list *ap, t_forme list)
{
    int     d;
    char    *tab;

    d = va_arg(ap, int);
    if (list.width > ft_len_num(d))
    {
        if (ft_strsearch(list.size, '-') == 1)
            tab = ft_after_d(ft_itoa(d), list);
    }
    return (tab);
}