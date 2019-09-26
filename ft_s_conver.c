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
    tab = (char *)malloc(sizeof(char) * list.width);
    n = list.width - 1;
    while (n > 0)
    {
        tab[i] = ' ';
        i++;
        n--;
    }
    j = 0;
    while (str[j])
    {
        tab[i] = str[i];
        i++;
        j++;
    }
    tab[i] = '\0';
    return (tab);
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
            printf("hello\n");
            ft_before_str(dst, list);
        }
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
    char *tab;
    char    *str2;

    str = va_arg(*ap, char *);
    str2 = ft_strdup(str);
    if ((list.precision < (int)ft_strlen(str)) && list.precision >= 0)
        str2[list.precision] = '\0';
    n = ft_strlen(str2);
    printf("%d\n", ft_strsearch(list.size, '-'));
    if (ft_strsearch(list.size, '-') == 1)
    {
        printf("here2\n");
        tab = ft_strncpy_white(list.tab, str2, list.size, list.width, list);
    }
    else
    {
        printf("here\n");
        tab = str2;
        printf("tab = %s\n",tab);
    }
    return (tab);
}
