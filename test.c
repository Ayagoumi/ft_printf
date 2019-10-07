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

// void    show_ieee754 (double f)
// {
//     t_fu  l;
//     int i;
//     char    *tab;

//     tab = (char*)malloc(150);
//     l.f = f;
//     tab[64] = '\0';
//     i = 63; 
//     while (i >= 0)
//     {
//         tab[i] = ((l.u >> i) & 1) + 48;
//         i--;
//     }
//     ft_putrevstr(tab);
// }

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

// char *ft_power_of_2(char    *n, long long   m)
// {
//     char    *tab;

//     tab =  (char *)malloc(sizeof(char) * ((int)(1 + m*log10(2)) + 1)); //1 + b * log10(a) gives u the number of digits in a eponant number
//     tab[(int)(1 + m*log10(2))] = '\0';
//     ft_memset(tab, '0', (int)(1 + m*log10(2)));
//     tab[(int)(1 + m*log10(2)) - 1] = 1;
//     printf("%s\n",tab);
//     while (m > 0)
//     {
//         tab = mult(tab,n);
//         m--;
//     }
//     return (tab);
// }

// double f(t_double l)
// {
//     if (from_binary(l.mantissa) == 0)
//         return ((from_binary(l.mantissa) * pow(2, 1074)));
//     else
//         return ((pow(2,52) + from_binary(l.mantissa)) * pow(2, l.exponant-1075));
// } 

// extract the signe mantissa and exponent fron the number intered for long long

// t_double    alloc_t_double()
// {
//     t_double    ll;

//     ll.mantissa = (char*)malloc(53);
//     ll.mantissa[52] = '\0';
//     ll.exponant = (char*)malloc(12);
//     ll.exponant[11] = '\0';
//     ll.signe = (char*)malloc(2);
//     ll.signe[1] = '\0';
//     return(ll);
// }

// t_double    something(long long l, int  i)
// {
//     t_double    ll;
//     int j;
//     int r;
//     int k;

//     j = 0;
//     r = 0;
//     k = 0;
//     ll = alloc_t_double();
//     while (i >= 0)
//     {
//         if (i > 62)
//         {
//             ll.signe[k] = ((l >> i) & 1) + 48;
//             k++;
//         }
//         else if (i > 51 && i <= 62)
//         {
//             ll.exponant[j] = ((l >> i) & 1) + 48;
//             j++;
//         }
//         else
//         {
//             ll.mantissa[r] = ((l >> i) & 1) + 48;
//             r++;
//         }
//         i--;
//     }
//     return (ll);
// }

// t_double    show_IEEE754(double f)
// {
//     t_fu  l;
//     int i;
//     t_double    ll;
    
//     l.f = f;
//     i = 63;
//     ll = something(l.u, i);
//     return (ll);
// }

//turm binary to string number

// char    *from_binary(char     *str)
// {
//     char        *tab;
//     char        *tmp;
//     int         i;
//     int         j;
//     char        c[2];

//     tab = ft_strnew(22);
//     i = ft_strlen(str) - 1;
//     j = 0;
//     while (i >= 0)
//     {        
//         c[0] = *str;
//         c[1] = '\0';
//         tmp = add(tab, mult(c, ft_power_of_2("2",j)));
//         free(tab);
//         tab = tmp;
//         i--;
//         j++;
//     }
//     free(tmp);
//     return (tab);
// }

float ft_power(long long n, long long   m)
{

    if (m == 0)
        return (1);
    if (m < 0)
        return ((long double)1/n * ft_power(n , m + 1));
    else
        return (n * ft_power(n , m - 1));
}

// stock mantissa and exponent and signe

t_double    man_exp_signe(double    m)
{
    t_fu        l;
    t_double    t;
    long long   n;

    ft_memcpy(&n, &m, 8);
    t.mantissa = (n & 0x000FFFFFFFFFFFFF);
    t.exponant = ((n & 0x7FF0000000000000) >> 52);
    t.signe = ((l.u & 0x8000000000000000) >> 63);
    return (t);
}

char    *insert_an_1(char    *tab, size_t    l)
{
    tab = malloc(sizeof(char) * (l + 1));
    ft_memset(tab, '0', l - 1);
    tab[l - 1] = '1';
    tab[l] = '\0';
    return (tab);
}

char *ft_power_of_2(char    *n, long long   m)
{
    char    *tab;
    char    *str;
    char    *tmp;
    int     i;
    int     j;

    if (m > 0)
    {
        //tab = insert_an_1(tab, 31694);
        tab = "1";
        while (m > 0)
        {
            tmp = mult(tab,n);
            free(tab);
            tab = tmp;
            m--;
        }
    }
    else if (m <= 0)
    {
        j = -m;
        //tab = insert_an_1(tab, j + 2);
        while (j > 0)
        {
            tab = mult(tab, "5");
            j--;
        }
        tab[1] = '.';
    }
    i = 0;
    // while(tab[i])
    // {
    //     if (tab[i] =='0')
    //         i++;
    //     else
    //         break;
    // }
    str = ft_strdup(tab + i);
    free(tab);
    return (str);
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

int main (void) 
{
    int i = 0;
    double f = 4.5;//14617454154645668435135135484563151648432168.6;
    long double f2 = 0.0000000000000000000000000000000000000000000000006;
    char    *tab;
    long long m;
    t_double    l;

    //l = show_IEEE754(f);

    // l = man_exp_signe(f);

    // printf("%lld\n",l.exponant);
    // printf("%lld\n",l.mantissa);
    // printf("%lld\n",l.signe);

    printf("%s\n",ft_power_of_2("2", -4));

    //printf("%.100s\n", apply_IEEE754(l));
    // printf("%.100Lf\n",f2);
    // char    *str1 = "11";
    // char    *str2 = "5";
    // char  *tab1 = add(str1, "-1");
    // printf("%lld\n",from_binary(l.exponant));
    // printf("%s\n",l.exponant);
    // printf("%f\n", log10(12.6) + 1);
    // printf("%lld\n", ft_len_num((long long)12.6));
    // printf("%d\n",(int)(1 + 10*log10(2)));
    // printf("%s\n", mult("0","0"));
    // char    *tab2 = ft_power_of_2("2", 20);
    // printf("%s\n",tab2);
    // printf("%f\n",pow(2,20));
    // printf("%s\n",from_binary(l.exponant));
    // printf("%s\n",l.exponant);
    //free(tab2);
    //printf("%d\n", (2 << 30) % 10);
    //printf("%s\n",apply_IEEE754(f));
    return 0;
}
