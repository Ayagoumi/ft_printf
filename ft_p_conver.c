#include "ft_printf.h"

// warning if flags and precision is specified

char *ft_type_pointer(va_list *ap, t_forme list)
{
    list->tab = ft_itoa(av_arg(ap, int));
}