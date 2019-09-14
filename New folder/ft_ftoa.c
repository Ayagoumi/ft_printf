#include "ft_printf.h"

int power(int   n)
{
    int result;

    result = 10;
    if (n == 0)
        result = 1;
    while (n > 1)
    {
        result = result * 10;
        n--;
    }
    return (result);
}

/*int     check_float_precision(char  *precision)
{
    int pre;

    if (atoi(precision) >= 7)
        pre = '6';
    else
        pre = atoi(precision);
    return (pre);
}*/

char    *ft_ftoa(float n, t_forme list)
{
    char    *str;
    char    *s;
    int     int_n;
    int     num_digit;
    int     i;
    int     signe;
    float     fact;
    long long float_n;
    float   fract;


    i = num_digit = 0;
    signe = 1;
    if (n < 0)
    {
        signe = -1;
        n = n * (-1);
    }
    int_n = (int)n;
    if (int_n == 0)
        num_digit = 1;
    while(int_n > 0)
    {
            num_digit++; //how many digits in the decimal part of the number
            int_n = int_n/10;
    }
    int_n = (int)n;
    fract = (n - int_n); // converting the factroral part of the number into a decimal one
    //printf("fract = %f\n", fract);
    float_n = (long long)(fract * power(list.precision + 1)); // multipliying it to the presicion +1 to take the number that is next to it tou round it up
    //printf("float_n = %lld\n",float_n);
    if  ((float_n % 10) >= 5) // round up the number if it's >= 5
        float_n += 10;
    float_n = float_n / 10;
    if (signe == -1)
    {
        str = malloc(sizeof(num_digit + list.precision + 2));
        ft_bzero(str, (num_digit + list.precision + 2));
        str[0] = '-';
        i = 1;
    }
    else
    {
        str = malloc(sizeof(num_digit + list.precision + 1));
        ft_bzero(str, (num_digit + list.precision + 1));
    }
    ft_strcpy(str + i,ft_itoa(int_n));
    if (list.precision > 0)
    {
        str[num_digit + i] = '.';
        ft_strcpy(str + (num_digit + i + 1) , ft_itoa(float_n));
    }
    str[num_digit + list.precision + 1] = '\0';
    return (str);
}

/*int main()
{
    printf("%s\n", ft_ftoa(10.2569846, "32"));
    //printf("%e\n",10.2569841);
    //printf("%u\n", -2);
    //printf("%d\n", 105369);
    //printf("%i\n", 105369);
    return (0);
}*/