#include "ft_printf.h"

// if flags are used show warning

char    *ft_after(char c, t_forme list)
{
    char    *tab;
    int     i;
    int     n;

    i = 0;
    if (ft_strsearch(list.size, '-') == 1)
    {
        tab = (char *)malloc(sizeof(char) * list.width);
        tab[i] = c;
        n = list.width - 1;
        while (n > 0)
        {
            i++;
            tab[i] = ' ';
            n--;
        }
        tab[list.width] = '\0';
    }
    else
        return (NULL);
    return (tab);
}

char    *ft_before(char c, char signe, t_forme  list)
{
    char    *tab;
    int     n;
    int     i;
    char    s;

    i = 0;
    tab = (char *)malloc(sizeof(char) * list.width);
    n = list.width - 1;
    if (signe == '+')
        s = ' ';
    else
        s = '0';
    while (n > 0)
    {
        tab[i] = signe;
        i++;
        n--;
    }
    tab[list.width - 1] = c;
    tab[list.width] = '\0';
    return (tab);
}

char *ft_type_char(va_list *ap, t_forme list)
{
    char c;
    char *tab;

    c = va_arg(*ap, int);
    if (list.width > 1)
    {
        if (ft_strsearch(list.size, '-') == 1)
            tab = ft_after(c, list);
        else if (ft_strsearch(list.size, '0') == 1)
            tab = ft_before(c, '0', list);
        else
            tab = ft_before(c, ' ', list);
    }
    else
    {
        tab = (char *)malloc(sizeof(char) * 2);
        tab[0] = c;
        tab[1] = '\0';
    }
    return (tab);
}