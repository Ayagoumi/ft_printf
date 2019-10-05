/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_conver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:17:34 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/09/14 21:37:31 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

char	*ft_lltoa(long long nb)
{
    int		i;
    char	*tab;
	int		j;

	j = num_dec(nb);
	tab = (char *)malloc(sizeof(char) * (j + 1));
	tab[j] = '\0';
	tab[0] = '0';
	if (nb < 0)
	{
		tab[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
        tab[--j] = (((long long)(nb) % 10)) + 48;
		nb /= 10;
	}
    return (tab);
}

long long		ft_len_num(long long d)
{
	int i;

	i = 0;
	if (d < 0)
	{
		i = 1;
		d = d * (-1);
	}
	while (d > 0)
	{
		d = d / 10;
		i++;
	}
	return (i);
}

char	*ft_after_d(char *d, t_forme list)
{
	char *tab;
	char *str;
	int i;
	int n;

	i = 0;
	if (list.width > ft_strlen(d))
	{
		tab = (char *)malloc(sizeof(char) * list.width + 1);
		n = list.width - ft_strlen(d);
		while (n > 0)
		{
			i++;
			tab[i] = ' ';
			n--;
		}
		tab[i] = '\0';
		ft_strcpy(tab + i, d);
	}
	return (tab);
}

char	*ft_type_int(va_list *ap, t_forme list)
{
	long long     d;
	char    *tab;

	if (list.flags && (ft_strcmp(list.flags, "ll") == 0 || ft_strcmp(list.flags, "l") == 0)) //long long and long in 64bit computar has the same range 
		d = (long)va_arg(*ap, long long);
	else if (list.flags && ft_strcmp(list.flags, "h") == 0)
		d = (short)va_arg(*ap, long long);
	else if (list.flags && ft_strcmp(list.flags, "hh") == 0)
		d = (char)va_arg(*ap, int);
	else
		d = (long)va_arg(*ap, long long);
	tab = ft_lltoa(d);
    tab = ft_strncpy_white(list.tab, tab, list.size, list.width, list);
	return (tab);
}

// there a problem in h and hh