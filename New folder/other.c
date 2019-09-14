#include "libft/libft.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

int precision(const char *f,...)
{
    va_list ap;
    int n,d;
    
    n = 0;
    va_start(ap, f);
    while(*f)
    {
        if(*f == '%')
        {
            *f++;
            while (ft_isdigit(*f) == 1)
            {
                *f++;
            }
            if (*f == '.')
            {
                *f++;
                n = ft_atoi(f);
            }
            while (ft_isdigit(*f) == 1)
                *f++;
            if (*f == 'd')
            {
                d = va_arg(ap, int);
                printf("%d\n", d);
            }
        }
        *f++;
    }
    va_end(ap);
}

int main()
{
    float lol = 10;
    precision("%.20d\n",lol);
    printf("%.5s\n","hello world");
    return (0);
}