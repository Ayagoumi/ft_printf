#include "ft_printf.h"

int     div_hex(size_t   n)
{
    int     i;

    i = 0;
    while (n != 0)
    {
        n /= 16;
        i++;
    }
    return (i);
}

char    *to_hexa_x(size_t  n)
{
    size_t   m;
    char        *tab;
    char        *str;
    int         j;

    tab = (char *)malloc(sizeof(char) * 17);
    str = (char *)malloc(sizeof(char) * div_hex(n) + 1);
    tab = ft_strcpy(tab, "0123456789abcdef");
    j = div_hex(n) - 1;
	str[div_hex(n)] = '\0';
    if (n == 0)
        return ("0");
    else
    {
    while (n != 0)
    {
        m = n % 16;
        n /= 16;
        str[j] = tab[m];
        j--;
    }
    }
    return (str);
}

char    *to_hexa_X(size_t  n)
{
    size_t   m;
    char        *tab;
    char        *str;
    int         j;

    tab = (char *)malloc(sizeof(char) * 17);
    str = (char *)malloc(sizeof(char) * div_hex(n) + 1);
    tab = ft_strcpy(tab, "0123456789abcdef");
    j = div_hex(n) - 1;
	str[div_hex(n)] = '\0';
    if (n == 0)
        return ("0");
    else
    {
    while (n != 0)
    {
        m = n % 16;
        n /= 16;
        str[j] = tab[m];
        j--;
    }
    }
    return (str);
}

char	*ft_type_hex(va_list *ap, t_forme list)
{
	size_t     h;
	char    *tab;

	h = va_arg(*ap, size_t);
    if (list.type == 'x')
    {
        tab = to_hexa_x(h);
        if (ft_strsearch(list.size, '#') == 1 && (ft_strcmp(tab,"0") != 0))
            tab = ft_strjoin("0x", tab);
    }
    else if (list.type == 'X')
    {
        tab = to_hexa_X(h);
        if (ft_strsearch(list.size, '#') == 1 && (ft_strcmp(tab,"0") != 0))
            tab = ft_strjoin("0X", tab);
    }
	return (tab);
}