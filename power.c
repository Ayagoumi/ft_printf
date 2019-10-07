/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:52:32 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/10/05 23:19:51 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

    tab = insert_an_1(tab, 300);
    while (m > 0)
    {
        tmp = mult(tab,n);
        free(tab);
        tab = tmp;
        m--;
    }
    i = 0;
    while(tab[i])
    {
        if (tab[i] =='0')
            i++;
        else
            break;
    }
    str = ft_strdup(tab + i);
    free(tab);
    return (str);
}

int main (void) 
{
    int i = 0;
    long double f = 414617454154645668435135135484563151648432168.6;
    long double f2 = 0.0000000000000000000000000000000000000000000000006;
    char    *tab;
    long long m;
    t_double    l;

    //printf("%.100s\n", apply_IEEE754(l));
    // printf("%.100Lf\n",f2);
    // char    *str1 = "11";
    // char    *str2 = "5";
    // char  *tab1 = add(str1, "-1");
    // printf("%lld\n",from_binary(l.exponant));
    // printf("%s\n",l.exponant);
    // printf("%f\n", log10(12.6) + 1);
    // printf("%lld\n", ft_len_num((long long)12.6));
    // printf("%d\n",(int)(1 + 10*log10(2)));
    // printf("%s\n", mult("0","0"));
    char    *tab2 = ft_power_of_2("2", 64);
    printf("%s\n",tab2);
    free(tab2);
    //printf("%d\n", (2 << 30) % 10);
    //printf("%s\n",apply_IEEE754(f));
    return 0;
}
