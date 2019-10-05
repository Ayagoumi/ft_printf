#include "ft_printf.h"

// if flags are used show warning

int     ft_strsearch(char *str, int c)
{
    int i;

    i = 0;
    if (str == NULL)
        return (0);
    while (str[i])
    {
        if (str[i] == (char)c)
            return (1);
        i++;
    }
    return (0);
}

char    *ft_before_str(char *str, t_forme  list)
{
    char    *tab;
    int     n;
    int     i;
    int     j;

    i = 0;
    n = list.width - ft_strlen(str);
    tab = (char *)malloc(sizeof(char) * list.width + 1);
    while (n > 0)
    {
        tab[i] = ' ';
        i++;
        n--;
    }
    j = 0;
    while (str[j] != '\0')
    {
        tab[i] = str[j];
        i++;
        j++;
    }
    tab[i] = '\0';
    return (tab);
}

int     ft_stricpy(char   **dst, const char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        (*dst)[i] = src[i];
        i++;
    }
    (*dst)[i] = '\0';
    return (i);
}

char    *ft_strncpy_white(char  *dst, char  *src, char  *signe, int n, t_forme list)
{
    int     i;

    i = 0;
    n = n - ft_strlen(src);
    dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + n));
    
    if (n > 0)
    {
        if (ft_strsearch(signe, '-') == 1)
        {
            i = ft_stricpy(&dst, src);
            while (n > 0)
            {
                dst[i] = ' ';
                i++;
                n--;
            }
            dst[i] = '\0';
        }
        else
            dst = ft_before_str(src, list);
    }
    else
        dst = ft_strcpy(dst, src);
    return (dst);
}

char *ft_type_string(va_list *ap, t_forme list)
{
    int n;
    char *str;
    char *tab;

    str = ft_strdup(va_arg(*ap, char *));
    // if ((list.precision < (int)ft_strlen(str)) && list.precision >= 0)
    //     str[list.precision] = '\0';
    n = ft_strlen(str);
    tab = ft_strncpy_white(list.tab, str, list.size, list.width, list);
    return (tab);
}
