#include "ft_printf.h"

char		*stock_digit(char **str, char *pourc)
{
	int i;

	i = 0;
	while (ft_isdigit(pourc[i]))
		i++;
	*str = ft_strndup(pourc, i);
	return(pourc += sizeof(char) * i);		
}

char		*stock_flag(char *str, char *pourc)
{
	if (pourc[0] == '-' || pourc[0] == '+' || pourc[0] == ' ' || pourc[0] == '#')
	{
		*str = pourc[0];
		pourc++;
	}
	else
		*str = NULL;
	return (pourc);
}

char		*stock_width(char **str, char *pourc)
{
	if (ft_isdigit(pourc[0]))
		pourc = stock_digit(str, pourc);	
	else if (pourc[0] == '*')
	{
		*str == '*';
		pourc++;
	}
	else
		*str = NULL;
	return (pourc);
}

char		*stock_precision(char **str, char *pourc)
{
	if (pourc[0] == '.')
		pourc = stock_digit(str, &pourc[1]);	
	else if (pourc[0] == '*')
	{
		*str == '*';
		pourc++;
	}
	else
		*str = NULL;
	return (pourc);
}

char		*stock_lenght(char **str, char *pourc)
{
	if ((pourc[0] == 'h' && pourc[1] == 'h') || (pourc[0] == 'l' && pourc[1] == 'l'))
	{
		*str = ft_strndup(pourc, 2);
		pourc += sizeof(char) * 2;
	}
	else if (pourc[0] == 'h' || pourc[0] == 'l' || pourc[0] == 'j' || pourc[0] == 'z')
	{		
		*str = ft_strndup(pourc, 1);
		pourc++;
	}
	return (pourc);
}


t_format	*ft_listnew_format(char *pourc, va_list ap)
{
	t_format	*list;

	list = (t_format*)ft_memalloc(sizeof(t_format));
	list->ap = ap;
	pourc = stock_flag(&list->flag, pourc);
	pourc = stock_width(&list->width, pourc);
	pourc = stock_precision(&list->precision, pourc);
	pourc = stock_lenght(&list->lenght, pourc);
	list->type = pourc[0];
	return (list);
}

void		ft_listadd_format(t_format *list, t_format **begin)
{
	t_format	*tmp;

	if ((tmp = *begin))
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list;
	}
	else
		*begin = list;
}

int		ft_printf(const char *format, ...)
{
	int		f;
	va_list		ap;
	char		*pourc;
	t_format	**lst;

	lst = (t_format**)ft_memalloc(sizeof(t_format*));
	va_start(ap, format);
	pourc = format;
	while (pourc)
	{	
		pourc = ft_strchr(pourc, '%');
		if (pourc[1] != '%')
			ft_listadd_format(ft_listnew_format(&pourc[1], ap), lst);
	}
	while (ft_strcmp(format, pourc) != 0)
	{
		else if (format[0] == '\')
			ft_putstr(format);
		else
			ft_putchar(format[0]);
		format++;
	}
	va_end(ap);
	return (f);
}
