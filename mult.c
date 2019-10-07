/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:37:17 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/10/07 16:38:29 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *return_0(char  *str, size_t    n)
{
    str = (char  *)malloc(sizeof(char) * n + 1);
    ft_memset(str, '0', n + 1);
    str[n] = '\0';
    return (str);
}

char    *mult(char  *str1, char     *str2)
{
    t_mult_add  m;

    m.len1 = ft_strlen(str1);
    m.len2 = ft_strlen(str2);
    if (m.len1 == 0 || m.len2 == 0)
        return(m.tab = return_0(m.tab, 1));
    m.tab = return_0(m.tab, (m.len1 + m.len2) - 1);
    m.i = m.len1;
    while(--m.i >= 0)
    {
        m.j = m.len2;
        m.i_tab = m.i + (m.j - 1);
        m.carry = 0;
        while (--m.j >= 0)
        {
            m.sum = (str1[m.i] - '0') * (str2[m.j] - '0') + (m.tab[m.i_tab] - '0') + m.carry;
            m.tab[m.i_tab] = (m.sum % 10) + '0';
            m.carry = m.sum / 10;
			m.i_tab--;
        }
        m.tab[m.i_tab] += m.carry;
    }
    return (m.tab);
}