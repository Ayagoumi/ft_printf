#include "ft_printf.h"

void    ft_putnbr_unsigned(unsigned int n)
{
    if (n <= 9)
        ft_putchar(n + '0');
    else if (n > 9)
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
    }
}