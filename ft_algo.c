/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 23:15:31 by amineau           #+#    #+#             */
/*   Updated: 2016/02/26 04:30:55 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	c;

	if (lst)
		;
	c = va_arg(ap, unsigned int);
	size = 1;
	*res = ft_straddc(*res, c);
	return (size);
}
int		ft_string(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	*str;

	if (lst)
		;
	str = va_arg(ap, char*);
	size = ft_strlen(str);
	*res = ft_strcln1join(*res, str);
	return (size);
}

char	*point_incrust(char *str, int n, char c)
{
	int 	i;
	char	*dest;

	i = ft_strlen(str);
	dest = (char*)ft_memalloc(sizeof(char) * (i + 1));
	dest = ft_strncpy(dest, str, i - n);
	if (n == 0 && c != '#')
		return (dest);
	dest[i - n] = '.';
	while (n-- != -1)
		dest[i - n] = str[i - n - 1];
	dest[i + 1] = '\0';
	ft_strdel(&str);
	return (dest);
}

int		ft_float(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	*str;

	str = ft_itoa((int)(va_arg(ap, double) * ft_power(lst->precision, 10)));
	str = point_incrust(str, lst->precision, lst->conv);
	size = ft_strlen(str);
	*res = ft_strclnjoin(*res, str);
	return (size);
}

int		ft_int(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	*str;

	if (lst)
		;
	str = ft_itoa(va_arg(ap, int));
	size = ft_strlen(str);
	*res = ft_strclnjoin(*res, (const char*)str);
	return (size);
}

int		ft_unint(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	*str;

	if (lst)
		;
	str = ft_itoa(va_arg(ap, unsigned int));
	size = ft_strlen(str);
	*res = ft_strclnjoin(*res, str);
	return (size);
}

int		ft_form(t_format **lst, char **format, char **res, va_list ap)
{
	int			size;
	t_format	*tmp;

	tmp = *lst;
	size = 0;
	if (tmp->type == 's')
		size = ft_string(tmp, res, ap);
	else if (tmp->type == 'c')
		size = ft_char(tmp, res, ap);
	else if (tmp->type == 'd' || tmp->type == 'i')
		size = ft_int(tmp, res, ap);
	else if (tmp->type == 'f')
		size = ft_float(tmp, res, ap);
	else if (tmp->type == 'u')
		size = ft_unint(tmp, res, ap);
	*format += tmp->size;
	*lst = tmp->next;
	ft_lstdel_format(tmp);
	return (size);
}

int		ft_algo(t_format *list, char *format, char **res, va_list ap)
{
	int		er;

	er = 0;
	while (*format && er != -1)
	{
		if (*format != '%')
		{
			*res = ft_straddc(*res, *format);
			format++;
		}
		else if (format[1] == '%')
		{
			*res = ft_straddc(*res, format[1]);
			format += 2;
		}
		else
			er = ft_form(&list, &format, res, ap);
	}
	if (er == -1)
		return (-1);
	return (ft_strlen(*res));
}
