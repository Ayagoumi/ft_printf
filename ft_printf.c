#include "ft_printf.h"

size_t to_octa(size_t n)
{
    if (n == 0)
        return (0);
    return (n % 8 + 10 * to_octa(n / 8));
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    char *phrase;
    int n;
    t_forme *list;
    int     m;

    va_start(ap, format);
    n = ft_strlen(format);
    phrase = (char*)malloc(n * sizeof(char));
    ft_memcpy(phrase, format, n);
    list = (t_forme*)malloc(sizeof(t_forme));
    list = final_format(&ap, phrase, &(*list));
    printf("list.size = %s\n", list->size);
    printf("list.width = %d\n", list->width);
    printf("list.precision = %d\n", list->precision);
    printf("list.flags = %s\n", list->flags);
    printf("list.type = %c\n", list->type);
    if (list->type == 's')
        list->tab = ft_type_string(&ap, *list);
    if (list->type == 'c')
        list->tab = ft_type_char(&ap, *list);
    //final_format(ap, phrase, *list);
    printf("%s|\n", list->tab);
    va_end(ap);
    return (0);
}

void     ft_skip(char **phrase)
{
    while (**phrase != '%')
        *(*phrase)++;
}

t_forme *final_format(va_list *ap, char *phrase, t_forme *list)
{
    char *signe[5];

    ft_skip(&phrase);
    if (*phrase == '%')
    {
        *phrase++;
        list->size = ft_signe(&phrase);
        //printf("%s\n",list.size); // temp
        list->width = ft_width(ap,&phrase);
        //printf("%d\n", list.width); // temp
        list->precision = ft_precision(ap, &phrase);
        //printf("%d\n", list.precision); // temp
        list->flags = ft_flags(&phrase);
        //printf("%s\n", list.flags); //temp
        list->type = ft_type(&phrase);
        //printf("%c\n", list.type); //temp
    }
    return (list);
}

char    *ft_signe(char **phrase)
{
    char *signe;
    int i;

    signe = (char*)malloc(sizeof(char) * 2048);
    i = 0;
    while (**phrase == '+' || **phrase == '-' || **phrase == '#' || **phrase == '0' || **phrase == ' ')
    {
        signe[i] = **phrase;
        i++;
        *(*phrase)++;
    }
    signe[i] = '\0';
    i = 0;
    signe = delete_repeat(signe);
    return (signe);
}

char *delete_repeat(char *signe)
{
    int i;
    int j;
    int k;
    int n;

    i = 0;
    n = ft_strlen(signe);
    while (signe[i] && i < n - 1)
    {
        j = i + 1;
        while (signe[j])
        {
            if (signe[i] == signe[j])
            {
                k = j;
                while (signe[k])
                {
                    signe[k] = signe[k + 1];
                    k++;
                }
                signe[k] = '\0';
                j--;
            }
            j++;
        }
        i++;
    }
    return (signe);
}

size_t ft_width(va_list *ap, char **phrase)
{
    size_t wid;

    if (**phrase == '*')
    {
        wid = va_arg(*ap, size_t);
        *(*phrase)++;
    }
    else
    {
        wid = ft_atoi(*phrase);
        while (ft_isdigit(**phrase) == 1)
            *(*phrase)++;
    }
    return (wid);
}

size_t ft_precision(va_list *ap, char **phrase)
{
    int i;
    size_t numb;

    i = 0;
    if (**phrase == '.')
    {
        *(*phrase)++;
        if (**phrase == '*')
        {
            numb = va_arg(*ap, size_t);
            *(*phrase)++;
        }
        else
        {
            numb = ft_atoi(*phrase);
            while (ft_isdigit(**phrase) == 1)
                *(*phrase)++;
        }
    }
    return (numb);
}

char *ft_flags(char **phrase)
{
    char    *str;
    char *flag;

    str = (char *)malloc(sizeof(char) * 4);
    ft_strcpy(str, "lhL");
    if (**phrase == str[0])
    {
        if ((*(*phrase)++) == str[0])
        {
            *(*phrase)++;
            return ("ll");
        }
        else
            return ("l"); 
    }
    if (**phrase == str[1])
    {
        if ((*(*phrase)++) == str[1])
        {
            *(*phrase)++;
            return ("hh");
        }
        else
            return ("h");
    }
    if (**phrase == str[2])
    {
        *(*phrase)++;
        return ("L");
    }
    return (flag);
}

char ft_type(char **phrase)
{
    char   type;

    if (**phrase == 'd')
        type = 'd';
    if (**phrase == 'i')
        type = 'i';
    if (**phrase == 'o')
        type = 'o';
    if (**phrase == 'u')
        type = 'u';
    if (**phrase == 'x')
        type = 'x';
    if (**phrase == 'X')
        type = 'X';
    if (**phrase == 'c')
        type = 'c';
    if (**phrase == 'p')
        type = 'p';
    if (**phrase == 's')
        type = 's';
    if (**phrase == 'f')
        type = 'f';
    if (**phrase == '%')
        type = ' ';
    return (type);
}

int main()
{
    char    *p;

    p = "hello";
    //ft_printf("%d|\n", p);
    printf("%+- #4d|\n", -12);
    printf("%d\n", ft_itoa(-15215352454));
    return (0);
}