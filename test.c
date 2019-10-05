#include "ft_printf.h"
#include <math.h>

/*typedef union   s_fu
{
    double f;
    long long u;
}               t_fu;

typedef struct  s_double
{
    char    *signe;
    char    *exponant;
    char    *mantissa;
}               t_double;


void    ft_putrevstr(char   *str)
{
    int n;

    n = ft_strlen(str);
    while (n--)
    {
        ft_putchar(str[n]);
        if (n % 4 == 0)
            ft_putchar(' ');
    }
    ft_putchar('\n');
}

void    show_ieee754 (double f)
{
    t_fu  l;
    int i;
    char    *tab;

    tab = (char*)malloc(150);
    l.f = f;
    tab[64] = '\0';
    i = 63; 
    while (i >= 0)
    {
        tab[i] = ((l.u >> i) & 1) + 48;
        i--;
    }
    ft_putrevstr(tab);
}

t_double    show_IEEE754(double f)
{
    t_fu  l;
    int i;
    char    *tab;
    t_double    ll;
    int j,r,k;

    ll.mantissa = (char*)malloc(53);
    ll.exponant = (char*)malloc(12);
    ll.signe = (char*)malloc(2);
    l.f = f;
    i = 63;
    ll.mantissa[53] = '\0';
    ll.exponant[12] = '\0';
    ll.signe[2] = '\0';
    j = 0;
    r = 0;
    k = 0;
    while (i >= 0)
    {
        if (i > 62)
        {
            ll.signe[k] = ((l.u >> i) & 1) + 48;
            k++;
        }
        if (i > 51 && i <= 62)
        {
            ll.exponant[j] = ((l.u >> i) & 1) + 48;
            j++;
        }
        if (i >= 0 && i < 52)
        {
            ll.mantissa[r] = ((l.u >> i) & 1) + 48;
            r++;
        }
        i--;
    }
    return (ll);
}
char    *ft_strrev(char  *tab)
{
    char    *str;
    int     i;
    int     j;

    i = ft_strlen(tab);
    j = 0;
    str = (char*)malloc(sizeof(char) * (i));
    str[i] = '\0';
    while (i--)
    {
        str[i] = tab[j];
        j++;
    }
    return (str);
}

float ft_power(long long n, long long   m)
{

    if (m == 0)
        return (1);
    if (m < 0)
        return ((long double)1/n * ft_power(n , m + 1));
    else
        return (n * ft_power(n , m - 1));
}*/

/*char    *ft_ftoa(long double n, t_forme list)
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
}*/

float ft_power(long long n, long long   m)
{

    if (m == 0)
        return (1);
    if (m < 0)
        return ((long double)1/n * ft_power(n , m + 1));
    else
        return (n * ft_power(n , m - 1));
}

long long   from_binary(char     *str)
{
    long long   n;
    int         i;
    int         j;

    i = ft_strlen(str) - 1;
    n = 0;
    j = 0;
    while (i >= 0)
    {
        n = n + ((str[i] - '0')* ft_power(2,j));
        i--;
        j++;
    }
    return (n);
}

t_double    alloc_t_double()
{
    t_double    ll;

    ll.mantissa = (char*)malloc(53);
    ll.mantissa[52] = '\0';
    ll.exponant = (char*)malloc(12);
    ll.exponant[11] = '\0';
    ll.signe = (char*)malloc(2);
    ll.signe[1] = '\0';
    return(ll);
}

void    ft_putrevstr(char   *str)
{
    int n;

    n = ft_strlen(str);
    while (n--)
    {
        ft_putchar(str[n]);
        if (n % 4 == 0)
            ft_putchar(' ');
    }
    ft_putchar('\n');
}

void    show_ieee754 (double f)
{
    t_fu  l;
    int i;
    char    *tab;

    tab = (char*)malloc(150);
    l.f = f;
    tab[64] = '\0';
    i = 63; 
    while (i >= 0)
    {
        tab[i] = ((l.u >> i) & 1) + 48;
        i--;
    }
    ft_putrevstr(tab);
}

t_double    something(long long l, int  i)
{
    t_double    ll;
    int j;
    int r;
    int k;

    j = 0;
    r = 0;
    k = 0;
    ll = alloc_t_double();
    while (i >= 0)
    {
        if (i > 62)
        {
            ll.signe[k] = ((l >> i) & 1) + 48;
            k++;
        }
        else if (i > 51 && i <= 62)
        {
            ll.exponant[j] = ((l >> i) & 1) + 48;
            j++;
        }
        else
        {
            ll.mantissa[r] = ((l >> i) & 1) + 48;
            r++;
        }
        i--;
    }
    return (ll);
}

t_double    show_IEEE754(double f)
{
    t_fu  l;
    int i;
    t_double    ll;
    
    l.f = f;
    i = 63;
    ll = something(l.u, i);
    return (ll);
}

// char    *ft_strrev(char  *tab)
// {
//     char    *str;
//     int     i;
//     int     j;

//     i = ft_strlen(tab);
//     j = 0;
//     str = (char*)malloc(sizeof(char) * (i));
//     str[i] = '\0';
//     while (i--)
//     {
//         str[i] = tab[j];
//         j++;
//     }
//     return (str);
// }

char    *return_0(char  *str, size_t    n)
{
    str = (char  *)malloc(sizeof(char) * n + 1);
    ft_memset(str, '0', n + 1);
    str[n] = '\0';
    return (str);
}

char    *mult(char  *str1, char     *str2)
{
    t_mult_add  m;

    m.len1 = ft_strlen(str1);
    m.len2 = ft_strlen(str2);
    if (m.len1 == 0 || m.len2 == 0 || atoi(str1) == 0 || atoi(str2) == 0)
        return(m.tab = return_0(m.tab, 1));
    m.tab = return_0(m.tab, (m.len1 + m.len2) - 1);
    m.i = m.len1;
    while(--m.i >= 0)
    {
        m.j = m.len2;
        m.i_tab = m.i + (m.j - 1);
        m.carry = 0;
        while (--m.j >= 0)
        {
            m.sum = (str1[m.i] - '0') * (str2[m.j] - '0') + (m.tab[m.i_tab] - '0') + m.carry;
            m.tab[m.i_tab] = (m.sum % 10) + '0';
            m.carry = m.sum / 10;
			m.i_tab--;
        }
        m.tab[m.i_tab] += m.carry;
    }
    return (m.tab);
}

void    ft_swap_char(char    **str1, char    **str2)
{
    char    *str;

    str = *str1;
    *str1 = *str2;
    *str2 = str;
}

void    ft_swap_int(int    *a, int    *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

char    *for_add(char   *str1, char     *str2, char *tab, int  len1, int len2)
{
    t_mult_add  m;

    str1 = ft_strrev(str1);
    str2 = ft_strrev(str2);
    m.carry = 0;
    m.i = 0;
    while (m.i < len1)
    {
        m.sum = (str1[m.i] - '0') + (str2[m.i] - '0') + m.carry;
        tab[m.i] = (m.sum % 10) + '0';
        m.carry = m.sum / 10;
        m.i++;
    }
    while (m.i < len2)
    {
        m.sum = (str2[m.i] - '0') + m.carry;
        tab[m.i] = (m.sum % 10) + '0';
        m.carry = m.sum / 10;
        m.i++;
    }
    if (m.carry)
        tab[m.i] = m.carry + '0';
    return (tab);
}

char    *add(char   *str1, char     *str2)
{
    t_mult_add  m;

    m.len1 = ft_strlen(str1);
    m.len2 = ft_strlen(str2);
    if (m.len1 > m.len2)
    {
        ft_swap_char(&str1, &str2);
        ft_swap_int(&m.len1, &m.len2);
        m.tab = malloc(sizeof(char) * m.len1);
        m.tab[m.len1] = '\0';
    }
    else
    {
        m.tab = malloc(sizeof(char) * m.len2);
        m.tab[m.len2] = '\0';
    }
    m.tab = for_add(str1, str2, m.tab, m.len1, m.len2);
    return (m.tab = ft_strrev(m.tab));
}

char *ft_power_of_2(char    *n, long long   m)
{
    char    *tab;

    tab =  malloc(sizeof(char) * (ft_len_num(m) * ft_strlen(n)));
    ft_memset(tab, '1', 1);
    if (m > 0)
    {
        while (m != 0)
        {
            tab = mult(tab, n);
            m--;
        }
    }
    else
    {
        while (m <= 0)
        {
            tab = mult(tab, n);
            m++;
        }
    }
    return (tab);
}

char       *apply_IEEE754(t_double  ll)
{
    char    *str1;
    char    *str2;

    if (from_binary(ll.mantissa) == 0)
    {
        str1 = ft_lltoa(from_binary(ll.mantissa));
        str2 = ft_power_of_2("2",- 1075);
        return (mult(str1, str2));
    }
    else
    {
        str1 = add(ft_power_of_2("2",52), ft_lltoa(from_binary(ll.mantissa)));
        str2 = ft_power_of_2("2", (from_binary(ll.exponant) - 1075));
        return (mult(str1, str2));
    }
}
int main (void) 
{
    int i = 0;
    long double f = 414617454154645668435135135484563151648432168.6;
    long double f2 = 0.0000000000000000000000000000000000000000000000006;
    char    *tab;
    long long m;
    t_double    l;

    l = show_IEEE754(f);

    // printf("%s\n", l.signe);
    // printf("%s\n", l.exponant);
    // printf("%s\n", l.mantissa);

    // printf("%lld\n", from_binary(l.signe));
    // printf("%lld\n", from_binary(l.exponant));
     printf("%lld\n", from_binary(l.mantissa));
     printf("%s\n", ft_lltoa(from_binary(l.mantissa)));

    //printf("%.100s\n", apply_IEEE754(l));
    // printf("%.100Lf\n",f2);
    char    *str1 = "11";
    char    *str2 = "5";
    char  *tab1 = add(str1, "-1");
    printf("%s\n",ft_power_of_2("2",- 1075));
    printf("%.1090f\n", pow(2, -1075));
    //printf("%s\n",apply_IEEE754(f));
    return 0;
}
