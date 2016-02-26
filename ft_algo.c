/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 23:15:31 by amineau           #+#    #+#             */
/*   Updated: 2016/02/26 17:16:54 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_white(char c, int n)
{
	char	*str;
	int		i;

	if (!(str = (char*)ft_memalloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (i != n)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

char	*ft_justif(char *str, int just, char flag)
{
	size_t	size;
	char	sign;
	char	*ptr;

	size = (int)ft_strlen(str);
	if (just <= size)
		return (str);
	//printf("flag du |%s| : %c\n",str,flag);
	if (flag == '0' && (str[0] == '-' || str[0] == '+'))
	{
		ptr = ft_strnew(1);
		ptr[0] = str[0];
		return (ft_strjoin(ft_strclnjoin(ptr, ft_white(flag, just - size)), &str[1]));
	}
	if (flag == ' ' || flag == '0')
		return (ft_strclnjoin(ft_white(flag, just - size), str));
	else
		return (ft_strclnjoin(str, ft_white(' ', just - size)));
}

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
	char	*dest;

	if (lst)
		;
	str = va_arg(ap, char*);
	size = ft_strlen(str);
	if (!(dest = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (-1);
	dest = ft_strcpy(dest, str);
	*res = ft_strclnjoin(*res, ft_justif(dest, lst->width, lst->just));
	return (size);
}

int		nbrdigit(uintmax_t nb)
{
	int pow;

	pow = 0;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		pow++;
	}
	return (pow);
}

int		ft_float(t_format *lst, char **res, va_list ap)
{
	int			digit;
	double		nb;
	intmax_t	integer;
	intmax_t	decimal;
	char		*str;

	str = ft_strnew(0);
	nb = va_arg(ap, double);
	integer = nb;
	decimal = ABS(arrondi((nb - integer) * ft_power(lst->precision, 10)));
	if (*(uintmax_t*)&nb >= 0x8000000000000000)
		str = ft_straddc(str, '-');
	else if (lst->sign == '+' || lst->sign == ' ')
		str = ft_straddc(str, lst->sign);
	str = ft_strclnjoin(str, ft_itoa(ABS(integer)));
	if (lst->conv == '#' || lst->precision != 0)
		str = ft_straddc(str, '.');
	if (lst->precision)
	{
		digit = nbrdigit(decimal);
		while (++digit < lst->precision)
			str = ft_straddc(str, '0');
		str = ft_strclnjoin(str, ft_itoa(decimal));
	}
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
	return (1);
}

int		ft_scienti(t_format *lst, char **res, va_list ap)
{
	int			digit;
	double		nb;
	intmax_t	integer;
	intmax_t	decimal;
	char		*str;

	str = ft_strnew(0);
	nb = va_arg(ap, double);
	/***************************************/
	/***************************************/
	/***************************************/
	/***************************************/
	integer = nb;
	decimal = ABS(arrondi((nb - integer) * ft_power(lst->precision, 10)));
	if (*(uintmax_t*)&nb >= 0x8000000000000000)
		str = ft_straddc(str, '-');
	else if (lst->sign == '+' || lst->sign == ' ')
		str = ft_straddc(str, lst->sign);
	str = ft_strclnjoin(str, ft_itoa(ABS(integer)));
	if (lst->conv == '#' || lst->precision != 0)
		str = ft_straddc(str, '.');
	if (lst->precision)
	{
		digit = nbrdigit(decimal);
		while (++digit < lst->precision)
			str = ft_straddc(str, '0');
		str = ft_strclnjoin(str, ft_itoa(decimal));
	}
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
	return (1);
}

int		ft_int(t_format *lst, char **res, va_list ap)
{
	int			size;
	intmax_t	nb;
	char		*str;

	if (lst)
		;
	str = ft_itoa(va_arg(ap, int));
	size = ft_strlen(str);
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
	return (size);
}

int		ft_unint(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	*str;

	if (lst)
		;
	str = ft_itoa_unsi(va_arg(ap, unsigned int));
	size = ft_strlen(str);
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
	return (size);
}

int		ft_octal(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	*str;

	if (lst->conv == '#')
		*res = ft_straddc(*res, '0');
	str = ft_itoa_unsi_base(va_arg(ap, unsigned int), 8, 'a');
	size = ft_strlen(str);
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
	return (size);
}

int		ft_binaire(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	*str;

	if (lst->conv == '#')
		*res = ft_straddc(*res, '0');
	str = ft_itoa_unsi_base(va_arg(ap, unsigned int), 2, 'a');
	size = ft_strlen(str);
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
	return (size);
}

int		ft_adrpoint(t_format *lst, char **res, va_list ap)
{
	int			size;
	char		*str;

	if (lst)
		;
	*res = ft_straddc(ft_straddc(*res, '0'), lst->type + 8);
	str = ft_itoa_unsi_base(va_arg(ap, uintmax_t), 16, lst->type + 8);
	size = ft_strlen(str);
	*res = ft_strclnjoin(*res, str);
	return (size);
}
int		ft_hexa(t_format *lst, char **res, va_list ap)
{
	int			size;
	char		*str;

	str = NULL;
	if (lst->conv == '#')
	{
		str = ft_strnew(2);
		str[0] = '0';
		str[1] = lst->type;
	}
	str = ft_strclnjoin(str, ft_itoa_unsi_base(va_arg(ap, unsigned int) , 16, lst->type));
	size = ft_strlen(str);
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
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
	else if (tmp->type == 'd' || tmp->type == 'i' || tmp->type == 'D')
		size = ft_int(tmp, res, ap);
	else if (tmp->type == 'f')
		size = ft_float(tmp, res, ap);
	else if (tmp->type == 'u' || tmp->type == 'U')
		size = ft_unint(tmp, res, ap);
	else if (tmp->type == 'o' || tmp->type == 'O')
		size = ft_octal(tmp, res, ap);
	else if (tmp->type == 'b' || tmp->type == 'B')
		size = ft_binaire(tmp, res, ap);
	else if (tmp->type == 'e' || tmp->type == 'E')
		size = ft_scienti(tmp, res, ap);
	else if (tmp->type == 'x' || tmp->type == 'X')
		size = ft_hexa(tmp, res, ap);
	else if (tmp->type == 'p')
		size = ft_adrpoint(tmp, res, ap);
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
