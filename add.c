/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:37:59 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/10/07 16:39:05 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_swap_char(char    **str1, char    **str2)
{
    char    *str;

    str = *str1;
    *str1 = *str2;
    *str2 = str;
}

void    ft_swap_int(int    *a, int    *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

char    *for_add(char   *str1, char     *str2, char *tab, int  len1, int len2)
{
    t_mult_add  m;

    str1 = ft_strrev(str1);
    str2 = ft_strrev(str2);
    m.carry = 0;
    m.i = 0;
    while (m.i < len1)
    {
        m.sum = (str1[m.i] - '0') + (str2[m.i] - '0') + m.carry;
        tab[m.i] = (m.sum % 10) + '0';
        m.carry = m.sum / 10;
        m.i++;
    }
    while (m.i < len2)
    {
        m.sum = (str2[m.i] - '0') + m.carry;
        tab[m.i] = (m.sum % 10) + '0';
        m.carry = m.sum / 10;
        m.i++;
    }
    if (m.carry)
        tab[m.i] = m.carry + '0';
    return (tab);
}

char    *add(char   *str1, char     *str2)
{
    t_mult_add  m;

    m.len1 = ft_strlen(str1);
    m.len2 = ft_strlen(str2);
    if (m.len1 > m.len2)
    {
        ft_swap_char(&str1, &str2);
        ft_swap_int(&m.len1, &m.len2);
        m.tab = malloc(sizeof(char) * m.len1);
        m.tab[m.len1] = '\0';
    }
    else
    {
        m.tab = malloc(sizeof(char) * m.len2);
        m.tab[m.len2] = '\0';
    }
    m.tab = for_add(str1, str2, m.tab, m.len1, m.len2);
    return (m.tab = ft_strrev(m.tab));
}