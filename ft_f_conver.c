#include "ft_printf.h"

void    ft_putrevstr(char   *str)
{
    int n;

    n = ft_strlen(str);
    while (n--)
    {
        ft_putchar(str[n]);
        if (n % 4 == 0)
            ft_putchar(' ');
    }
    ft_putchar('\n');
}

void    show_ieee754 (double f)
{
    t_fu  l;
    int i;
    char    *tab;

    tab = (char*)malloc(150);
    l.f = f;
    tab[64] = '\0';
    i = 63; 
    while (i >= 0)
    {
        tab[i] = ((l.u >> i) & 1) + 48;
        i--;
    }
    ft_putrevstr(tab);
}

t_double    alloc_t_double()
{
    t_double    ll;

    ll.mantissa = (char*)malloc(53);
    ll.mantissa[53] = '\0';
    ll.exponant = (char*)malloc(12);
    ll.exponant[12] = '\0';
    ll.signe = (char*)malloc(2);
    ll.signe[2] = '\0';
    return (ll);
}

t_double    something(long long l, int  i)
{
    t_double    ll;
    int j;
    int r;
    int k;

    j = 0;
    r = 0;
    k = 0;
    while (i >= 0)
    {
        if (i > 62)
        {
            ll.signe[k] = ((l >> i) & 1) + 48;
            k++;
        }
        if (i > 51 && i <= 62)
        {
            ll.exponant[j] = ((l >> i) & 1) + 48;
            j++;
        }
        if (i >= 0 && i < 52)
        {
            ll.mantissa[r] = ((l >> i) & 1) + 48;
            r++;
        }
        i--;
    }
    return (ll);
}

t_double    show_IEEE754(double f)
{
    t_fu  l;
    int i;
    t_double    ll;

    ll = alloc_t_double();
    l.f = f;
    i = 63;

    ll = something(l.u, i);
    return (ll);
}
// char    *ft_strrev(char  *tab)
// {
//     char    *str;
//     int     i;
//     int     j;

//     i = ft_strlen(tab);
//     j = 0;
//     str = (char*)malloc(sizeof(char) * (i));
//     str[i] = '\0';
//     while (i--)
//     {
//         str[i] = tab[j];
//         j++;
//     }
//     return (str);
// }

float ft_power(long long n, long long   m)
{

    if (m == 0)
        return (1);
    if (m < 0)
        return ((long double)1/n * ft_power(n , m + 1));
    else
        return (n * ft_power(n , m - 1));
}