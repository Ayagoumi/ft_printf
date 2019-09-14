#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

typedef struct  s_forme
{
    
    char    *size;
    size_t     width;
    size_t     precision;
    char    type;
    char    *flags;
    char    *tab;
    //struct s_forme *next;
}               t_forme;

size_t  to_octa(size_t n);
void ft_skip(char **phrase);
char *ft_signe(char **phrase);
char *ft_flags(char **phrase);
size_t ft_precision(va_list *ap, char **phrase);
size_t ft_width(va_list *ap, char **phrase);
char ft_type(char **phrase);
t_forme *final_format(va_list *ap, char *phrase, t_forme *list);
char *delete_repeat(char *signe);
char *ft_ftoa(float n, t_forme list);
void ft_type_s(va_list *ap, t_forme list);

/* s */
char *ft_type_string(va_list *ap, t_forme list);
char *ft_strncpy_white(char *dst, char *src, int n);
int ft_strsearch(char *str, int c);

/* c */
char *ft_type_char(va_list *ap, t_forme list);
char *ft_after(char c, t_forme list);
char *ft_before(char c, char signe, t_forme list);

#endif