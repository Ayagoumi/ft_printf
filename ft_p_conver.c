#include "ft_printf.h"

// warning if flags and precision is specified

char *ft_type_poin(va_list *ap, t_forme list)
{
     unsigned long  p;
     char           *tab;

     p = va_arg(*ap, unsigned long);
     tab = ft_strjoin("0x",to_hexa_X(p));
     if (list.width > ft_strlen(tab))
          tab = before_space(tab, list, ' ');
     return (tab);
}