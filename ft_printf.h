/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:58:19 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/09/15 14:58:25 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

typedef struct      s_forme
{
	char            *size;
	size_t          width;
	int             precision;
	char            type;
	char            *flags;
	char            *tab;
	struct s_forme  *next;
}                   t_forme;

//c
char    *ft_after(char c, t_forme list);
char    *ft_before(char c, char signe, t_forme  list);
char	*ft_type_char(va_list *ap, t_forme list);

//d
char	*ft_lltoa(long long nb);
char	*ft_long(long	nb);
long long		ft_len_num(long long d);
char	*ft_after_d(char *d, t_forme list);
char	*ft_type_int(va_list *ap, t_forme list);

//s
int     ft_strsearch(char *str, int c);
char    *ft_before_str(char *str, t_forme  list);
char    *ft_strncpy_white(char  *dst, char  *src, char  *signe, int n, t_forme list);
char *ft_type_string(va_list *ap, t_forme list);

//p
char *ft_type_poin(va_list *ap, t_forme list);

//x
int     div_hex(size_t   n);
char    *to_hexa_x(size_t  n);
char    *to_hexa_X(size_t  n);
char	*ft_type_hex(va_list *ap, t_forme list);

//o
size_t	to_octa(size_t n);
char    *ft_precision_oct(char  *str, t_forme list);
char    *after_spcae(char   *str, t_forme   list);
char    *before_space(char  *str, t_forme list, char    signe);
char    *change_tab(char    *str, t_forme   list);
int     num_dec(long long n);
char	*lltoa(long long nb);
char    *ft_type_oct(va_list *ap, t_forme list);

//f
long long    turn_to_binary(long long n);
char    *ft_ftoa(long double n, t_forme list);
char	*ft_type_float(va_list *ap, t_forme list);
long double     floating_point_only(long double m);

//ft_printf
char		ft_type(char   **phrase);
char		*ft_flags(char **phrase);
int		ft_precision(va_list *ap, char **phrase);
size_t		ft_width(va_list *ap, char **phrase);
char		*ft_signe(char **phrase);
t_forme		*final_format(va_list *ap, char **phrase, t_forme *list);
void		ft_skip(char **phrase);
int		ft_printf(const char *format, ...);

//long long	to_octa(long long n);
// char	*ft_type_oct(va_list *ap, t_forme list);
// char	*lltoa(long long nb);
// char    *before_space(char  *str, t_forme list, char    signe);
// int     num_dec(long long n);

// char	*ft_lltoa(long long nb);

// void    ft_skip(char **phrase);
// char    *ft_signe(char **phrase);
// char    *ft_flags(char **phrase);
// int     ft_precision(va_list *ap, char **phrase);
// size_t  ft_width(va_list *ap, char **phrase);
// char    ft_type(char **phrase);

// t_forme *final_format(va_list *ap, char *phrase, t_forme *list);
// char    *ft_strncpy_white(char  *dst, char  *src, char  *signe, int n, t_forme list);
// char    *ft_before_str(char *str, t_forme  list);

// char    *delete_repeat(char *signe);
// char    *ft_ftoa(float n, t_forme list);
// void    ft_type_s(va_list *ap, t_forme list);
// char    *ft_type_string(va_list *ap, t_forme list);
// //char    *ft_strncpy_white(char *dst, char *src, int n);
// int     ft_strsearch(char *str, int c);
// char    *ft_type_char(va_list *ap, t_forme list);
// char    *ft_after(char c, t_forme list);
// char    *ft_before(char c, char signe, t_forme list);

// //char	*lltoa(long long nb);

// char    *to_hexa_X(size_t  n);
// char    *to_hexa_x(size_t  n);
// int     div_hex(size_t   n);
// char	*ft_type_hex(va_list *ap, t_forme list);

// char *ft_type_poin(va_list *ap, t_forme list);

// char	*ft_type_int(va_list *ap, t_forme list);
#endif
