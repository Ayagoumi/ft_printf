/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 00:51:01 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/10/04 21:57:57 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_colors(char     **phrase)
{
    char    *tab;
    int     i;

    tab = malloc(sizeof(char) * 100);
    i = 0;
    if (ft_strsearch(*phrase, '}') == 1)
    {
        (void)*(*phrase)++;
        while (**phrase != '}' && **phrase)
        {
            tab[i] = **phrase;
            (void)*(*phrase)++;
            i++;
        }
        (void)*(*phrase)++;
        tab[i] = '\0';
        return (tab);
    }
    else
    {
        free(tab);
        ft_putchar(**phrase);
		(void)*(*phrase)++;
    }
    return (NULL);
}

void    apply_colors(char  *tab)
{
    if (tab && ft_strcmp(tab, "eoc") == 0)
        ft_putstr(RESET);
    else if (tab && ft_strcmp(tab, "green") == 0)
        ft_putstr(GREEN);
    else if (tab && ft_strcmp(tab, "red") == 0)
        ft_putstr(RED);
    else if (tab && ft_strcmp(tab, "yellow") == 0)
        ft_putstr(YELLOW);
    else if (tab && ft_strcmp(tab, "blue") == 0)
        ft_putstr(BLUE);
    else if (tab && ft_strcmp(tab, "magenta") == 0)
        ft_putstr(MAGENTA);
    else if (tab && ft_strcmp(tab, "cyan") == 0)
        ft_putstr(CYAN);
    else
        return ;
}