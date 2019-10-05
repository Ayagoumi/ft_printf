/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_conver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:58:50 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/10/05 14:32:49 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_strrev(char   *str)
{
    int n;
    int i;
    char    *tab;

    n = ft_strlen(str);
    tab = malloc(sizeof(char) * (n + 1));
    tab[n] = '\0';
    i = 0;
    while (n--)
    {
        tab[i] = str[n];
        i++;
    }
    return (tab);
}

char    *to_binary(long long   m, size_t    n)
{
    t_fu  l;
    int i;
    char    *tab;

    tab = (char*)malloc(n*8 + 1);
    tab[n*8] = '\0';
    i = n * 8 - 1; 
    while (i >= 0)
    {
        tab[i] = ((m >> i) & 1) + 48;
        i--;
    }
    return (ft_strrev(tab));
}


char    *ft_type_binary(va_list *ap, t_forme list)
{
	long long       d;
    int             n;
    char            *tab;
	if (list.flags && (ft_strcmp(list.flags, "ll") == 0 || ft_strcmp(list.flags, "l") == 0)) //long long and long in 64bit computar has the same range 
	{
        d = va_arg(*ap, long long);
        n = sizeof(long long);
    }
	else if (list.flags && ft_strcmp(list.flags, "h") == 0)
    {
		d = (short)va_arg(*ap, long long);
        n = sizeof(short);
    }
	else if (list.flags && ft_strcmp(list.flags, "hh") == 0)
    {
		d = (char)va_arg(*ap, int);
        n = sizeof(short);
    }
	else
    {
		d = (int)va_arg(*ap, long long);
        n = sizeof(int);
    }
    tab = to_binary(d, n);
    return (tab);
}