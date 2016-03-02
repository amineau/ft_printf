/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 11:28:40 by amineau           #+#    #+#             */
/*   Updated: 2016/03/02 20:25:04 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_decimal(long double nb, int prec)
{
	char	*str;
	int		i;

	if (prec < 0)
		return (NULL);
	str = ft_strnew(prec + 1);
	i = 0;
	str[i++] = '.';
	nb = ft_arrondi_double(nb, prec);
	while (prec != 0)
	{
		nb *= 10;
		if (prec != 1)
			str[i++] = (int)nb + 48;
		else
			str[i++] = ft_arrondi(nb) + 48;

		nb = (nb - (int)nb);
		prec--;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_integer(long double nb, char *str, int nbrdig, int prec)
{
	int			i;
	long double	tmp;

	str = ft_strnew(nbrdig);
	tmp = 0;
	i = 0;
	while (nbrdig != 0)
	{
		if (nbrdig != 1 || prec > 0)
			str[i++] = (int)nb + 48;
		else
			str[i++] = ft_arrondi(nb) + 48;
		nb = (nb - (int)nb) * 10;
		nbrdig--;
	}
	str[i] = '\0';
	return (str);
}

long double	ft_atof(char *str)
{
	long double	nb;
	int			size;
	int			i;

	size = ft_strlen(str);
	i = (str[0] == '-') ? 1 : 0;
	nb = 0;
	while (i < size)
		nb = nb * 10 + str[i++] - 48;	
	nb = (str[0] == '-') ? -nb : nb;
	return (nb);
}

void		ft_refresh(char **str)
{
	int		i;

	i = (int)ft_strlen(*str) - 1;
	while (i >= 0 && (*str)[i] != '-')
	{
		if (!ft_isdigit((*str)[i]) && (*str)[i] != '.')
		{
			(*str)[i] = '0';
			if ((i != 0 && (*str)[0] != '-') || (i != 1 && (*str)[0] == '-'))
			{
				if ((*str)[i - 1] != '.')
					(*str)[i - 1]++;
				else
					(*str)[i - 2]++;
			}
			else if (i == 1)
			{
				(*str)[0] = '1';
				*str = ft_strcln2join("-", *str);
			}
			else
				*str = ft_strcln2join("1", *str);
		}
		i--;
	}
}

char	*ft_exposant(char e, int dec)
{
	char	*str;

	str = ft_strnew(4);
	str[0] = e;
	str[1] = (dec < 0) ? '-' : '+';
	str[2] = (ABS(dec) / 10) + 48;
	str[3] = (ABS(dec) % 10) + 48;
	return (str);
}

char	*ft_itoa_scien_long(long double nb, int prec, char e)
{
	char		*str;
	long double	tmp;
	int			dec;
	int			neg;

	dec = 0;
	tmp = (*(long double*)&nb > DBL_MAX / 2) ? -nb : nb;
	neg = (*(long double*)&nb > DBL_MAX / 2) ? 1 : 0;
	str = ft_strnew(neg + 1);
	str[0] = '-';
	while (tmp < 1)
	{
		tmp *= 10;
		dec--;
	}
	while (tmp >= 10)
	{
		tmp /= 10;
		dec++;
	}
	str[neg] = (int)tmp + 48;
	str = ft_strcln1join(str, ft_decimal(tmp - (int)tmp, prec));
	ft_refresh(&str);
	str = ft_strclnjoin(str, ft_exposant(e, dec));
	return (str);
}

char	*ft_itoa_scien(double nb, int prec, char e)
{
	char	*str;
	double	tmp;
	int		dec;
	int		neg;

	dec = 0;
	tmp = (*(uintmax_t*)&nb > DBL_MAX / 2) ? -nb : nb;
	neg = (*(uintmax_t*)&nb > DBL_MAX / 2) ? 1 : 0;
	str = ft_strnew(neg + 1);
	str[0] = '-';
	while (tmp < 1)
	{
		tmp *= 10;
		dec--;
	}
	while (tmp >= 10)
	{
		tmp /= 10;
		dec++;
	}
	str[neg] = (int)tmp + 48;
	str = ft_strcln1join(str, ft_decimal(tmp - (int)tmp, prec));
	ft_refresh(&str);
	str = ft_strclnjoin(str, ft_exposant(e, dec));
	return (str);
}

char	*ft_itoa_long(long double nb, int prec)
{
	char		*str;
	long double	tmp;
	long double	tmp2;
	int			nbrdig;
	int			i;
	nbrdig = 1;
	tmp = (*(long double*)&nb > DBL_MAX / 2) ? -nb : nb;
	printf("tmp : %Lf\n",tmp);
	tmp2 = tmp;
	str = (*(long double*)&nb > DBL_MAX / 2) ? ft_strdup("-") : ft_strdup("");
	while (tmp > 10)
	{
		tmp /= 10;
		nbrdig++;
	}
	i = nbrdig;
	while (i > 8)
	{
		i -= 8;
		str = ft_strclnjoin(str, ft_integer(tmp, str, 8, 1));
		tmp = tmp2;
		tmp = tmp - (intmax_t)(tmp / ft_power(i, 10)) * ft_power(i, 10);
		tmp2 = tmp;
		while (tmp > 10)
			tmp /= 10;
	}
	tmp = (prec < 1) ? ft_arrondi_double(tmp, i - 1) : tmp;
	str = ft_strclnjoin(str, ft_integer(tmp, str, i, prec));
	str = ft_strcln1join(str, ft_decimal(ABS(nb - ft_atof(str)), prec));
	ft_refresh(&str);
	return (str);
}

char	*ft_itoa_double(double nb, int prec)
{
	char	*str;
	double	tmp;
	double	tmp2;
	int		nbrdig;
	int		i;

	nbrdig = 1;
	tmp = (*(uintmax_t*)&nb > DBL_MAX / 2) ? -nb : nb;
	tmp2 = tmp;
	str = (*(uintmax_t*)&nb > DBL_MAX / 2) ? ft_strdup("-") : ft_strdup("");
	while (tmp > 10)
	{
		tmp /= 10;
		nbrdig++;
	}
	i = nbrdig;
	while (i > 8)
	{
		i -= 8;
		str = ft_strclnjoin(str, ft_integer(tmp, str, 8, 1));
		tmp = tmp2;
		tmp = tmp - (intmax_t)(tmp / ft_power(i, 10)) * ft_power(i, 10);
		tmp2 = tmp;
		while (tmp > 10)
			tmp /= 10;
	}
	tmp = (prec < 1) ? ft_arrondi_double(tmp, i - 1) : tmp;
	str = ft_strclnjoin(str, ft_integer(tmp, str, i, prec));
	str = ft_strcln1join(str, ft_decimal(ABS(nb - ft_atof(str)), prec));
	ft_refresh(&str);
	return (str);
}
