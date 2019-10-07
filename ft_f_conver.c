/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_conver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:42:45 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/10/07 16:42:45 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

float ft_power(long long n, long long   m)
{

    if (m == 0)
        return (1);
    if (m < 0)
        return ((long double)1/n * ft_power(n , m + 1));
    else
        return (n * ft_power(n , m - 1));
}

// stock mantissa and exponent and signe

t_double    man_exp_signe(double    m)
{
    t_fu        l;
    t_double    t;
    long long   n;

    ft_memcpy(&n, &m, 8);
    t.mantissa = (n & 0x000FFFFFFFFFFFFF);
    t.exponant = ((n & 0x7FF0000000000000) >> 52);
    t.signe = ((l.u & 0x8000000000000000) >> 63);
    return (t);
}

char    *insert_an_1(char    *tab, size_t    l)
{
    tab = malloc(sizeof(char) * (l + 1));
    ft_memset(tab, '0', l - 1);
    tab[l - 1] = '1';
    tab[l] = '\0';
    return (tab);
}

char *ft_power_of_2(char    *n, long long   m)
{
    char    *tab;
    char    *str;
    char    *tmp;
    int     i;
    int     j;

    if (m > 0)
    {
        //tab = insert_an_1(tab, 31694);
        tab = "1";
        while (m > 0)
        {
            tmp = mult(tab,n);
            free(tab);
            tab = tmp;
            m--;
        }
    }
    else if (m <= 0)
    {
        j = -m;
        //tab = insert_an_1(tab, j + 2);
        while (j > 0)
        {
            tab = mult(tab, "5");
            j--;
        }
        tab[1] = '.';
    }
    i = 0;
    // while(tab[i])
    // {
    //     if (tab[i] =='0')
    //         i++;
    //     else
    //         break;
    // }
    str = ft_strdup(tab + i);
    free(tab);
    return (str);
}