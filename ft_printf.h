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

//light_colors
# define RESET "\x1b[0m"
# define GREEN  "\x1b[32m"
# define RED "\x1b[31m"
# define YELLOW  "\x1b[33m"
# define BLUE  "\x1b[34m"
# define MAGENTA  "\x1b[35m"
# define CYAN  "\x1b[36m"

//bold_colors
# define B_GREEN  "\x1b[1;32m"
# define B_RED "\x1b[1;31m"
# define B_YELLOW  "\x1b[1;33m"
# define B_BLUE  "\x1b[1;34m"
# define B_MAGENTA  "\x1b[1;35m"
# define B_CYAN  "\x1b[1;36m"

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

typedef struct  s_double
{
    long long    signe;
    long long    exponant;
    long long    mantissa;
}               t_double;

typedef union   s_fu
{
    double f;
    long long u;
}               t_fu;

typedef	struct s_mult_add
{
	int i;
    int j;
    int sum;
    int carry;
	int i_tab;
	int len1;
    int len2;
    char    *tab;
}				t_mult_add;

//c
char		*ft_after(char c, t_forme list);
char		*ft_before(char c, char signe, t_forme  list);
char		*ft_type_char(va_list *ap, t_forme list);

//d
char		*ft_lltoa(long long nb);
char		*ft_long(long	nb);
long long	ft_len_num(long long d);
char		*ft_after_d(char *d, t_forme list);
char		*ft_type_int(va_list *ap, t_forme list);

//s
int			ft_strsearch(char *str, int c);
char		*ft_before_str(char *str, t_forme  list);
char		*ft_strncpy_white(char  *dst, char  *src, char  *signe, int n, t_forme list);
char		*ft_type_string(va_list *ap, t_forme list);

//p
char		*ft_type_poin(va_list *ap, t_forme list);

//x
int			div_hex(size_t   n);
char		*to_hexa_x(size_t  n);
char		*to_hexa_X(size_t  n);
char		*ft_type_hex(va_list *ap, t_forme list);

//o
char		*to_octa(size_t n);
char		*ft_precision_oct(char  *str, t_forme list);
char		*after_spcae(char   *str, t_forme   list);
char		*before_space(char  *str, t_forme list, char    signe);
char		*change_tab(char    *str, t_forme   list);
int			num_dec(long long n);
char		*lltoa(long long nb);
char		*ft_type_oct(va_list *ap, t_forme list);

//f
long long	turn_to_binary(long long n);
char		*ft_ftoa(long double n, t_forme list);
char		*ft_type_float(va_list *ap, t_forme list);
long double	floating_point_only(long double m);
void		ft_putrevstr(char   *str);
char        *add(char   *str1, char     *str2);
char        *mult(char  *str1, char     *str2);

//b
char    *ft_type_binary(va_list *ap, t_forme list);
char    *to_binary(long long   m, size_t    n);
char    *ft_strrev(char   *str);

//ft_printf
char		ft_type(char   **phrase);
char		*ft_flags(char **phrase);
int			ft_precision(va_list *ap, char **phrase);
size_t		ft_width(va_list *ap, char **phrase);
char		*ft_signe(char **phrase);
t_forme		*final_format(va_list *ap, char **phrase, t_forme *list);
void		finaly(va_list		*ap, t_forme	*list);
void		ft_skip(char **phrase);
int			ft_printf(const char *format, ...);
void		no_name(va_list	*ap, char **phrase ,t_forme	**list);

//colors
char    *ft_colors(char     **phrase);
void    apply_colors(char  *tab);
#endif