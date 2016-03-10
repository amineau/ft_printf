/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 23:15:31 by amineau           #+#    #+#             */
/*   Updated: 2016/03/10 19:31:18 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wh(char c, int n)
{
	char	*str;
	int		i;

	str = ft_strnew(n + 1);
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
	else if (lst->wild_width)
		va_arg(ap, int);
	if (lst->precision == -1)
	{
		lst->precision = va_arg(ap, int);
		if (lst->precision < 0)
		{
			if (ft_strchr("eEfFgG",lst->type))
				lst->precision = 6;
			else if (ft_strchr("dDioOuUxXbB",lst->type))
				lst->precision = 1;
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

char	*ft_sign(char *str, char s)
{
	char	*sign;

	if (str[0] != '-' && s)
	{
		sign = ft_strnew(1);
		sign[0] = s;
		str = ft_strclnjoin(sign, str);
	}
	return (str);
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
	if (f == '0' && (ft_strchr("-+ ", str[0])))
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

int		ft_char(t_format *lst, va_list ap)
{
	int		size;
	char	c;
	char	*str;

	if (lst->type != 'c')
		c = lst->type;
	else
		c = va_arg(ap, unsigned int);
	size = (lst->width <= 1) ? 0 : lst->width - 1;
	if (lst->just == '-')
	{
		ft_putchar(c);
		ft_putstr(str = ft_wh(' ', size));
	}
	else
	{
		ft_putstr(str = ft_wh(lst->just, size));
		ft_putchar(c);
	}
	size = ft_strlen(str) + 1;
	return (size);
}

int		ft_string(t_format *lst, va_list ap)
{
	char	*str;
	int	size;

	if (!(str = va_arg(ap, char*)))
		str = ft_strdup("(null)");
	size = (lst->precision >= 0) ? lst->precision : (int)ft_strlen(str);
	str = ft_justif_string(ft_strndup(str, size), lst->width, lst->just);
	ft_putstr(str);
	size = ft_strlen(str);
	ft_strdel(&str);
	return (size);
}

int		ft_float(t_format *lst, va_list ap)
{
	char		*str;
	int	size;

	if (lst->precision == 0 && lst->conv != '#')
		lst->precision = -1;
	str = ft_float_size(lst, ap);
	str = ft_sign(str, lst->sign);
	str = ft_justif(str, lst->width, lst->just);
	ft_putstr(str);
	size = ft_strlen(str);
	ft_strdel(&str);
	return (size);
}

int		ft_scienti(t_format *lst, va_list ap)
{
	char		*str;
	int	size;

	if (lst->precision == 0 && lst->conv != '#')
		lst->precision = -1;
	str = ft_scien_size(lst, ap);
	str = ft_sign(str, lst->sign);
	str = ft_justif(str, lst->width, lst->just);
	ft_putstr(str);
	size = ft_strlen(str);
	ft_strdel(&str);
	return (size);
}

int		ft_int(t_format *lst, va_list ap)
{
	char		*str;
	int	size;

	ft_lenght_type(lst->type, &(lst->lenght));
	str = ft_precision(ft_signed_size(lst, 10, ap), lst->precision);
	str = ft_sign(str, lst->sign);
	str = ft_justif(str, lst->width, lst->just);
	ft_putstr(str);
	size = ft_strlen(str);
	ft_strdel(&str);
	return (size);
}

int		ft_unint(t_format *lst, va_list ap)
{
	char	*str;
	int	size;

	ft_lenght_type(lst->type, &(lst->lenght));
	str = ft_precision(ft_unsigned_size(lst, 10, ap), lst->precision);
	str = ft_justif(str, lst->width, lst->just);
	ft_putstr(str);
	size = ft_strlen(str);
	ft_strdel(&str);
	return (size);
}

int		ft_octal(t_format *lst, va_list ap)
{
	char	*str;
	char	*dest;
	int	size;

	dest = NULL;
	ft_lenght_type(lst->type, &(lst->lenght));
	lst->precision = (lst->conv == '#') ? lst->precision - 1 : lst->precision;
	str = ft_precision(ft_unsigned_size(lst, 8, ap), lst->precision);
	if (lst->conv == '#' && ft_strcmp(str, "0") != 0)
		dest = ft_strdup("0");
	str = ft_strclnjoin(dest, str);
	str = ft_justif(str, lst->width, lst->just);
	ft_putstr(str);
	size = ft_strlen(str);
	ft_strdel(&str);
	return (size);
}

int		ft_binaire(t_format *lst, va_list ap)
{
	char	*str;
	char	*dest;
	int	size;

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
	str = ft_justif(str, lst->width, lst->just);
	ft_putstr(str);
	size = ft_strlen(str);
	ft_strdel(&str);
	return (size);
}

int		ft_adrpoint(t_format *lst, va_list ap)
{
	char	*str;
	char	*dest;
	int	size;

	dest = ft_straddc(ft_strdup("0"), lst->type + 8);
	str = ft_precision(ft_itoa_unsi_base(va_arg(ap, uintmax_t), 16, lst->type + 8), lst->precision);
	str = ft_strclnjoin(dest, str);
	str = ft_justif(str, lst->width, lst->just);
	ft_putstr(str);
	size = ft_strlen(str);
	ft_strdel(&str);
	return (size);
}

int		ft_hexa(t_format *lst, va_list ap)
{
	char	*str;
	char	*dest;
	int	size;

	dest = NULL;
	str = ft_precision(ft_unsigned_size(lst, 16, ap), lst->precision);
	if (lst->conv == '#' && ft_atoi(str) != 0)
	{
		dest = ft_strnew(2);
		dest[0] = '0';
		dest[1] = lst->type;
	}
	str = ft_strclnjoin(dest, str);
	str = ft_justif(str, lst->width, lst->just);
	ft_putstr(str);
	size = ft_strlen(str);
	ft_strdel(&str);
	return (size);
}

int		ft_wint(t_format *lst, va_list ap)
{
	wint_t	w;
	int		size;
	int		blanc;
	char	*str;

	w = va_arg(ap, wint_t);
	size = ft_cntwint(w);
	blanc = (lst->width <= size) ? 0 : lst->width - 1;
	if (lst->just == '-')
	{
		ft_putwint(w, size);
		ft_putstr(str = ft_wh(' ', blanc));
	}
	else
	{
		ft_putstr(str = ft_wh(lst->just, blanc));
		ft_putwint(w, size);
	}
	return (size);
}

int		ft_wchar(t_format *lst, va_list ap)
{
	wint_t	w;
	int		size;
	char	*str;

	w = va_arg(ap, wint_t);
	if (lst->just == '-')
	{
		size = ft_cntwint(w);
		ft_putwint(w, size);
		ft_putstr(str = ft_wh(' ', size - 1));
	}
	else
	{
		size = ft_cntwint(w);
		ft_putstr(str = ft_wh(lst->just, size - 1));
		ft_putwint(w, size);
	}
	return (size);
}

int		ft_form(t_format **lst, char **format, va_list ap)
{
	int			size;
	t_format	*tmp;

	tmp = *lst;
	size = 0;
	if (tmp->size != 1)
	{
		ft_wildcard(*lst, ap);
		if (tmp->type == 's')
			size = ft_string(tmp, ap);
		else if (tmp->type == 'S' || (tmp->type == 's' && ft_strcmp(tmp->lenght, "l") == 0))
			size = ft_wchar(tmp, ap);
		else if (tmp->type == 'c')
			size = ft_char(tmp, ap);
		else if (tmp->type == 'C' || (tmp->type == 'c' && ft_strcmp(tmp->lenght, "l") == 0))
			size = ft_wint(tmp, ap);
		else if (tmp->type == 'd' || tmp->type == 'i' || tmp->type == 'D')
			size = ft_int(tmp, ap);
		else if (tmp->type == 'f' || tmp->type == 'F')
			size = ft_float(tmp, ap);
		else if (tmp->type == 'u' || tmp->type == 'U')
			size = ft_unint(tmp, ap);
		else if (tmp->type == 'o' || tmp->type == 'O')
			size = ft_octal(tmp, ap);
		else if (tmp->type == 'b' || tmp->type == 'B')
			size = ft_binaire(tmp, ap);
		else if (tmp->type == 'e' || tmp->type == 'E')
			size = ft_scienti(tmp, ap);
		else if (tmp->type == 'x' || tmp->type == 'X')
			size = ft_hexa(tmp, ap);
		else if (tmp->type == 'p')
			size = ft_adrpoint(tmp, ap);
		else
			size = ft_char(tmp, ap);
	}
	*format += tmp->size;
	*lst = tmp->next;
	ft_lstdel_format(tmp);
	return (size);
}

int		ft_algo(t_format *list, char *format, va_list ap)
{
	int		size;

	size = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			format++;
			size++;
		}
		else if (format[1] == '%')
		{
			ft_putchar(format[1]);
			format += 2;
			size++;
		}
		else
			size += ft_form(&list, &format, ap);
	}
	return (size);
}
