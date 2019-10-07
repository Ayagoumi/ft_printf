/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:39:30 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/10/07 16:40:32 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    printbits(void *p, int i)
{
    char bb;
    int  j;

    j = i;
    while (j-- > 1)
        p++;
    //p += i;
    while (i-- > 0)
    {
        j = 7;
        bb = *(char* )p;
        while (j >= 0)
        {
            printf("%u", ((bb >> j) & 1));
            j--;
        }
        p--;
        printf(" ");
    }
    printf("\n");
}