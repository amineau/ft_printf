/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 23:15:31 by amineau           #+#    #+#             */
/*   Updated: 2016/03/03 21:03:21 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wh(char c, int n)
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

void	ft_wildcard(t_format *lst, va_list ap)
{
	if (lst->width == -1)
	{
		lst->width = va_arg(ap, int);
		if (lst->width < 0)
		{
			lst->width = -lst->width;
			lst->just = '-';
		}
	}
	if (lst->precision == -1)
	{
		lst->precision = va_arg(ap, int);
		if (lst->precision < 0)
		{
			lst->precision = -lst->precision;
			lst->just = '-';
		}
	}
}

char	*ft_lenght_type(char c, char **str)
{
	if (ft_isupper(c) == 1)
		*str = ft_strcln1join(*str, "l");
	return (*str);
}

char	*ft_signed_size(t_format *lst, int base, va_list ap)
{
	if (ft_strcmp(lst->lenght, "hh") == 0)
		return (ft_itoa_base((char)va_arg(ap, int), base, lst->type));
	else if (ft_strcmp(lst->lenght, "h") == 0)
		return (ft_itoa_base((short)va_arg(ap, int), base, lst->type));
	else if (ft_strcmp(lst->lenght, "l") == 0)
		return (ft_itoa_base(va_arg(ap, long), base, lst->type));
	else if (ft_strcmp(lst->lenght, "ll") == 0)
		return (ft_itoa_base(va_arg(ap, long long), base, lst->type));
	else if (ft_strcmp(lst->lenght, "j") == 0)
		return (ft_itoa_base(va_arg(ap, intmax_t), base, lst->type));
	else if (ft_strcmp(lst->lenght, "z") == 0)
		return (ft_itoa_base(va_arg(ap, ssize_t), base, lst->type));
	else
		return (ft_itoa_base(va_arg(ap, int), base, lst->type));
}

char	*ft_unsigned_size(t_format *lst, int base, va_list ap)
{
	if (ft_strcmp(lst->lenght, "hh") == 0)
		return (ft_itoa_unsi_base((unsigned char)va_arg(ap, int), base, lst->type));
	else if (ft_strcmp(lst->lenght, "h") == 0)
		return (ft_itoa_unsi_base((unsigned short)va_arg(ap, int), base, lst->type));
	else if (ft_strcmp(lst->lenght, "l") == 0)
		return (ft_itoa_unsi_base(va_arg(ap, unsigned long), base, lst->type));
	else if (ft_strcmp(lst->lenght, "ll") == 0)
		return (ft_itoa_unsi_base(va_arg(ap, unsigned long long), base, lst->type));
	else if (ft_strcmp(lst->lenght, "j") == 0)
		return (ft_itoa_unsi_base(va_arg(ap, uintmax_t), base, lst->type));
	else if (ft_strcmp(lst->lenght, "z") == 0)
		return (ft_itoa_unsi_base(va_arg(ap, size_t), base, lst->type));
	else
		return (ft_itoa_unsi_base(va_arg(ap, unsigned int), base, lst->type));
}

char	*ft_float_size(t_format *lst, va_list ap)
{
	if (ft_strcmp(lst->lenght, "L") == 0)
		return (ft_itoa_long(va_arg(ap, long double), lst->precision));
	else	
		return (ft_itoa_double(va_arg(ap, double), lst->precision));
}

char	*ft_scien_size(t_format *lst, va_list ap)
{
	if (ft_strcmp(lst->lenght, "L") == 0)
		return (ft_itoa_scien_long(va_arg(ap, long double), lst->precision, lst->type));
	else	
		return (ft_itoa_scien(va_arg(ap, double), lst->precision, lst->type));

}

char	*ft_precision(char *str, int prec)
{
	int	t;

	t = (int)ft_strlen(str);
	if (prec <= t)
	{
		if ((ft_strcmp(str, "0") == 0 || ft_strcmp(str, "-0") == 0) && prec == 0)
			str[0] = '\0';
		return (str);
	}
	if (str[0] == '-')
		return (ft_strcln2join("-", ft_strcln1join(ft_wh('0', prec - t + 1), &str[1])));
	return (ft_strclnjoin(ft_wh('0', prec - t), str));
}

char	*ft_justif(char *str, size_t just, char f)
{
	size_t	t;
	char	*ptr;

	t = ft_strlen(str);
	if (just <= t)
		return (str);
	if (f == '0' && (str[0] == '-' || str[0] == '+'))
	{
		ptr = ft_strnew(1);
		ptr[0] = str[0];
		return (ft_strjoin(ft_strclnjoin(ptr, ft_wh(f, just - t)), &str[1]));
	}
	if (f == ' ' || f == '0')
		return (ft_strclnjoin(ft_wh(f, just - t), str));
	else
		return (ft_strclnjoin(str, ft_wh(' ', just - t)));
}

char	*ft_justif_string(char *str, size_t just, char f)
{
	size_t	t;

	t = ft_strlen(str);
	if (just <= t)
		return (str);
	if (f == ' ' || f == '0')
		return (ft_strclnjoin(ft_wh(f, just - t), str));
	else
		return (ft_strclnjoin(str, ft_wh(' ', just - t)));
}
int		ft_char(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	c;
	char	*str;

	size = 1;
	if (lst->type != 'c' && lst->type != 'C')
		c = lst->type;
	else
		c = va_arg(ap, unsigned int);
	str = ft_justif_string(ft_straddc(ft_strnew(0), c), lst->width, lst->just);
	*res = ft_strclnjoin(*res, str);
	return (size);
}

int		ft_string(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	*str;

	if (!(str = va_arg(ap, char*)))
		str = ft_strdup("(null)");
	size = (lst->precision >= 0) ? lst->precision : (int)ft_strlen(str);
	*res = ft_strclnjoin(*res, ft_justif_string(ft_strndup(str, size), lst->width, lst->just));
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
	char		*str;

	if (lst->precision == 0 && lst->conv != '#')
		lst->precision = -1;
	str = ft_float_size(lst, ap);
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
	return (1);
}

int		ft_scienti(t_format *lst, char **res, va_list ap)
{
	char		*str;

	str = ft_scien_size(lst, ap);
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
	return (1);
}

int		ft_int(t_format *lst, char **res, va_list ap)
{
	int			size;
	char		*str;

	ft_lenght_type(lst->type, &(lst->lenght));
	str = ft_precision(ft_signed_size(lst, 10, ap), lst->precision);
	if (str[0] != '-' && lst->sign)
		*res = ft_straddc(*res, lst->sign);
	size = ft_strlen(str);
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
	return (size);
}

int		ft_unint(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	*str;

	ft_lenght_type(lst->type, &(lst->lenght));
	str = ft_precision(ft_unsigned_size(lst, 10, ap), lst->precision);
	size = ft_strlen(str);
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
	return (size);
}

int		ft_octal(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	*str;
	char	*dest;

	dest = NULL;
	ft_lenght_type(lst->type, &(lst->lenght));
	str = ft_precision(ft_unsigned_size(lst, 8, ap), lst->precision);
	if (lst->conv == '#' && ft_strcmp(str, "0") != 0)
		dest = ft_strdup("0");
	str = ft_strclnjoin(dest, str);
	size = ft_strlen(str);
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
	return (size);
}

int		ft_binaire(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	*str;
	char	*dest;

	dest = NULL;
	ft_lenght_type(lst->type, &(lst->lenght));
	str = ft_precision(ft_unsigned_size(lst, 2, ap), lst->precision);
	if (lst->conv == '#' && ft_atoi(str) != 0)
	{
		dest = ft_strnew(2);
		dest[0] = '0';
		dest[1] = lst->type;
	}
	str = ft_strclnjoin(dest, str);
	size = ft_strlen(str);
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
	return (size);
}

int		ft_adrpoint(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	*str;
	char	*dest;

	dest = ft_straddc(ft_strdup("0"), lst->type + 8);
	str = ft_precision(ft_itoa_unsi_base(va_arg(ap, uintmax_t), 16, lst->type + 8), lst->precision);
	size = ft_strlen(str);
	str = ft_strclnjoin(dest, str);
	*res = ft_strclnjoin(*res, ft_justif(str, lst->width, lst->just));
	return (size);
}

int		ft_hexa(t_format *lst, char **res, va_list ap)
{
	int		size;
	char	*str;
	char	*dest;

	dest = NULL;
	str = ft_precision(ft_unsigned_size(lst, 16, ap), lst->precision);
	if (lst->conv == '#' && ft_atoi(str) != 0)
	{
		dest = ft_strnew(2);
		dest[0] = '0';
		dest[1] = lst->type;
	}
	str = ft_strclnjoin(dest, str);
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
	if (tmp->size != 1)
	{
		ft_wildcard(*lst, ap);
		if (tmp->type == 's')
			size = ft_string(tmp, res, ap);
		else if (tmp->type == 'c')
			size = ft_char(tmp, res, ap);
		else if (tmp->type == 'd' || tmp->type == 'i' || tmp->type == 'D')
			size = ft_int(tmp, res, ap);
		else if (tmp->type == 'f' || tmp->type == 'F')
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
		else
			size = ft_char(tmp, res, ap);
	}
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
		//	printf("res : %s || format : %s\n",*res, format);
	}
	if (er == -1)
		return (-1);
	return (ft_strlen(*res));
}
