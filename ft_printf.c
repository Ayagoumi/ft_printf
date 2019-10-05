/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:40:18 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/09/14 21:32:54 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// printf("\nlist.size = %s\n", list->next->size);
// printf("list.width = %zu\n", list->next->width);
// printf("list.precision = %d\n", list->next->precision);
// printf("list.flags = %s\n", list->next->flags);
// printf("list.type = %c\n", list->next->type);
// printf("---------------------------\n");

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_forme *list;
	char	*phrase;
	char	*tab;

	va_start(ap, format);
	phrase = ft_strdup(format);
	no_name(&ap, &phrase, &list);
	while (*phrase != '\0')
	{
		if (*phrase == '%' && *phrase != '\0')
		{
			no_name(&ap, &phrase, &list->next);
			list = list->next;
		}
		else if (*phrase == '{' && *phrase != '\0')
		{
			tab = ft_colors(&phrase);
			apply_colors(tab);
		}
		else if (*phrase != '\0')
		{
			ft_putchar(*phrase);
			(void)*phrase++;
		}
	}
	list = NULL;
	free(list);
	va_end(ap);
	return (0);
}

void	no_name(va_list	*ap, char **phrase ,t_forme	**list)
{
	if (!(*list = (t_forme*)malloc(sizeof(t_forme))))
		return ;
	*list = final_format(ap, phrase, *list);
	finaly(ap, *list);
	ft_putstr((*list)->tab);
}

void	finaly(va_list		*ap, t_forme	*list)
{
	if (list->type == 's'/* || list->type == 'S'*/)
		list->tab = ft_type_string(ap, *list);
	else if (list->type == 'c'/* || list->type == 'C'*/)
		list->tab = ft_type_char(ap, *list);
	else if (list->type == 'p'/* || list->type == 'P'*/)
		list->tab = ft_type_poin(ap, *list);
	else if (list->type == 'd' || list->type == 'i'\
		|| list->type == 'D' || list->type == 'I')
		list->tab = ft_type_int(ap, *list);
	else if (list->type == 'o' || list->type == 'O')
		list->tab = ft_type_oct(ap, *list);
	else if (list->type == 'u' || list->type == 'U')
		list->tab = ft_type_poin(ap, *list);
	else if (list->type == 'x' || list->type == 'X')
		list->tab = ft_type_hex(ap, *list);
	else if (list->type == 'b' || list->type == 'B')
		list->tab = ft_type_binary(ap, *list);
	// if (list->type == 'f' || list->type == 'F')
	// 	list->tab = ft_type_float(&ap, *list);
}

void		ft_skip(char **phrase)
{
	while (**phrase != '%' && **phrase != '\0')
		(void)*(*phrase)++;
}

t_forme		*final_format(va_list *ap, char **phrase, t_forme *list)
{
	if (**phrase == '%')
	{
		(void)*(*phrase)++;
		list->size = ft_signe(phrase);
		list->width = ft_width(ap, phrase);
		list->precision = ft_precision(ap, phrase);
		list->flags = ft_flags(phrase);
		list->type = ft_type(phrase);
	}
	return (list);
}

char		*ft_signe(char **phrase)
{
	char *signe;
	int i;

	signe = (char*)malloc(sizeof(char) * 6);
	i = 0;
	if (**phrase == '+' || **phrase == '-' || **phrase == '#' \
	|| **phrase == '0' || **phrase == ' ')
	{
		while (**phrase == '+' || **phrase == '-' || **phrase == '#' \
		|| **phrase == '0' || **phrase == ' ')
		{
			if (ft_strsearch(signe, **phrase) == 0)
			{
				signe[i] = **phrase;
				i++;
			}
			(void)*(*phrase)++;
		}
		signe[i] = '\0';
	}
	else
		return (NULL);
	return (signe);
}

size_t		ft_width(va_list *ap, char **phrase)
{
	size_t wid;

	if (**phrase == '*')
	{
		wid = va_arg(*ap, size_t);
		(void)*(*phrase)++;
	}
	else
	{
		wid = ft_atoi(*phrase);
		while (ft_isdigit(**phrase) == 1)
			(void)*(*phrase)++;
	}
	return (wid);
}

int		ft_precision(va_list *ap, char **phrase)
{
	int i;
	int	numb;

	i = 0;
	numb = -1;
	if (**phrase == '.')
	{
		(void)*(*phrase)++;
		if (**phrase == '*')
		{
			numb = va_arg(*ap, size_t);
			(void)*(*phrase)++;
		}
		else
		{
			numb = ft_atoi(*phrase);
			while (ft_isdigit(**phrase) == 1)
				(void)*(*phrase)++;
		}
	}
	return (numb);
}

char		*ft_flags(char **phrase)
{
	char    *str;

	str = (char *)malloc(sizeof(char) * 4);
	ft_strcpy(str, "lhL");
	if (**phrase == str[0])
	{
		(void)*(*phrase)++;
		if (**phrase == str[0])
		{
			(void)*(*phrase)++;
			return ("ll");
		}
		else
			return ("l"); 
	}
	if (**phrase == str[1])
	{
		(void)*(*phrase)++;
		if (**phrase == str[1])
		{
			(void)*(*phrase)++;
			return ("hh");
		}
		else
			return ("h"); 
	}
	if (**phrase == str[2])
	{
		(void)*(*phrase)++;
		return ("L");
	}
	return (NULL);
}

char		ft_type(char   **phrase)
{
	char	*tab;
	char	c;

	tab = ft_memcpy(tab, "diouxXscpb%%", 13);
	if (ft_strsearch(tab, **phrase) == 1)
	{
		c = **phrase;
		(void)*(*phrase)++;
		return (c);
	}
	return (char)(NULL);
}

int			main()
{
	// ft_printf("\x1b[31m %s","hello");
	// printf("Hello ");
	// printf("\033[0m");
	// printf("Hello ");

	//printf("%shello %d %s%s %30.60d everyone|\n",RED, 120, RESET,"world", 120);
	//ft_printf("{red}hello %lld {eoc}%s %30.60d everyone|\n",120,"world", 120);
	
	//printf("hello %30d|\n", 120);
	//ft_printf("hello %30d|\n", 120);

	//printf("%30s\n","hello world");
	long long j = -1;
	ft_printf("%20c love {red}%20.60s bitch %d {eoc}lol%s {cyan} %hb {eoc}|\n",'i',"you", 3000, "hi", 4294967295);

	// ft_printf("hello %30lo|\n", 9223372036854775807 * 2);
	// printf("hello %30lo|\n", 9223372036854775807 * 2);
	
	// ft_printf("hello %#lx|\n",9223372036854775807*2 + 2);
	// printf("hello %#lx|\n",9223372036854775807*2 + 2);
	
	// ft_printf("%21p\n",a);
	// printf("%21p|\n",a);

	// printf("hello %s|\n", lltoa(9223372036));
	// printf("hello %030lo|\n", -2147483648);

	// printf("%d\n",turn_to_binary(313));
	// ft_putnbr_base(313,"01");
	// printf("\n%d\n",num_dec(100111001 * pow(2,-9)));

	// ft_printf("%f\n", 1528276921.123456789123456789123456789);
	// printf("%.60f\n", 1528276921.123456789123456789123456789);

	// printf("%zu\n", to_octa(r));
	return (0);
}