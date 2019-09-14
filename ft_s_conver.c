#include "ft_printf.h"

// if flags are used show warning

int     ft_strsearch(char *str, int c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == (char)c)
            return (1);
        i++;
    }
    return (0);
}

char    *ft_strncpy_white(char  *dst, char  *src, int n)
{
    int     i;

    i = 0;
    n = n - ft_strlen(src);
    dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + n));
    
    if (n > 0)
    {
        while (src[i])
        {
            dst[i] = src[i];
            i++;
        }
        while (n > 0)
        {
            dst[i] = ' ';
            i++;
            n--;
        }
        dst[i] = '\0';  
    }
    else
    {
        while (src[i])
        {
            dst[i] = src[i];
            i++;
        }
    }
    return (dst);
}

char *ft_type_string(va_list *ap, t_forme list)
{
    int n;
    char *str;
    int wid;
    char *tab;
    char    *str2;

    str = va_arg(*ap, char *);
    str2 = ft_strdup(str);
    if (list.precision < ft_strlen(str))
        str2[list.precision] = '\0';
    
    n = ft_strlen(str2);
    if (ft_strsearch(list.size, '-') == 1)
        tab = ft_strncpy_white(list.tab, str2, list.width);
    else
        tab = str2;
    return (tab);
}