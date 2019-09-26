/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_conver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:11:45 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/09/24 12:15:52 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	to_octa(size_t n)
{
    if (n == 0)
		return (0);
	return (n % 8 + 10 * to_octa(n / 8));
}

char    *ft_precision_oct(char  *str, t_forme list)
{
    int     n;
    char    *tab;
    int     i;

    n = list.precision - ft_strlen(str);
    i = 0;
    if (n > 0)
    {
        tab = (char *)malloc(sizeof(char) * n + 1);
        while (i < n)
        {
            tab[i] = '0';
            i++;
        }
        str = ft_strjoin(tab, str);
    }
    return (str);
}

char    *after_spcae(char   *str, t_forme   list)
{
    char    *tab;
    int     i;
    int     n;

    i = ft_strlen(str);
        tab = (char *)malloc(sizeof(char) * (list.width + ft_strlen(str) + 1));
        n = (list.width - ft_strlen(str));
        tab = ft_strcpy(tab, str);
        while (n > 0)
        {
            tab[i] = ' ';
            i++;
            n--;
        }
        tab[i] = '\0';
    return (tab);
}

char    *before_space(char  *str, t_forme list, char    signe)
{
    char    *tab;
    int     i;
    int     n;

    i = 0;
        tab = (char *)malloc(sizeof(char) * (list.width + ft_strlen(str) + 1));
        n = (list.width - ft_strlen(str));
        if (n > 0)
        {
            while (i < n)
            {
                tab[i] = signe;
                i++;
            }
        }
        tab = ft_strjoin(tab, str);
    return (tab);
}

char    *change_tab(char    *str, t_forme   list)
{
    char    *tab;

    str = ft_precision_oct(str, list);
    if (ft_strsearch(list.size, '#') == 1)
        str = ft_strjoin("0", str);
    if (ft_strsearch(list.size, '-') == 1)
        tab = after_spcae(str, list);
    else if (ft_strsearch(list.size, '0') == 1 && list.width > ft_strlen(str) && list.precision < 0)
        tab = before_space(str, list, '0');
    else if (list.width > 0 && list.width > ft_strlen(str))
        tab = before_space(str, list, ' ');
    else
        return (str);  
    return (tab);
}

int     num_dec(long long n)
{
    int     i;

    i = 0;
    if (n < 0)
    {
        i++;
        n *= -1;
    }
    while (n > 0)
	{
        n = n / 10;
		i++;
	}
    return (i);
}

char	*lltoa(long long nb)
{
    int		i;
    char	*tab;
	int		j;
    long double    m;

	j = 0;
    i = 0;
    if (nb < 0)
        nb *= (-1);
	i = num_dec(nb);
    tab = (char *)malloc(sizeof(char) * (i + 1));
    tab[i + 1] = '\0';
    m = nb;
    while ((long long)m > 0)
        m /= 10; 
	while (i > 0)
	{
		m *= 10;
        tab[j] = (((long long)(m) % 10)) + 48;
		j++;
		i--;
	}
    return (tab);
}

char    *ft_type_oct(va_list *ap, t_forme list)
{
    size_t o;
    size_t      m;
    char        *tab;
    if (ft_strcmp(list.flags, "l") == 0)
        o = (long)va_arg(*ap, long long);
    else
        o = (size_t)va_arg(*ap, size_t);
    m = to_octa(o);
    tab = change_tab(ft_lltoa(m), list);
    return (tab);
}

/*char    *ft_type_oct(va_list *ap, t_forme list)
{
    int   o;
    long long   m;
    char        *tab;
    unsigned int    r;

    // if (ft_strcmp(list.flags, "ll") == 0)
    //     o = va_arg(*ap, long long);
    if (ft_strcmp(list.flags, "l") == 0)
        o = (long)va_arg(*ap, long long);
    if (ft_strcmp(list.flags, "hh") == 0)
        o = (short)va_arg(*ap, long long);
    if (ft_strcmp(list.flags, "h") == 0)
        o = (char)va_arg(*ap, long long);
    else
        o = (int)va_arg(*ap, int);
    m = to_octa(r);
    tab = change_tab(lltoa(m), list);
    return (tab);
}*/