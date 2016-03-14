/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 11:28:40 by amineau           #+#    #+#             */
/*   Updated: 2016/03/14 20:24:41 by amineau          ###   ########.fr       */
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

	str = ft_strnew(nbrdig);
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
/**********************ajouter '-' apres refresh***************************/
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
/************************************************************************/
char	*ft_exposant(char e, int dec)
{
	char	*str;
	int	i;

	str = ft_strnew(2);
	str[0] = e;
	str[1] = (dec < 0) ? '-' : '+';
	if (ABS(dec) < 10)
		str = ft_strclnjoin(ft_straddc(str, '0'), ft_itoa(ABS(dec)));
	else
		str = ft_strclnjoin(str, ft_itoa(ABS(dec)));
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

long double	ft_recup_long(long double dif, long double nb, int i)
{
	int	j;
	j = 0;
	while (j++ < i)
		dif *= 10;
	return (ABS(nb - dif));
}
char	*ft_itoa_long(long double nb, int prec)
{
	char		*str;
	long double	tmp;
	long double	tmp2;
	int			nbrdig;
	int			i;

	nbrdig = 1;
	i = 0;
	tmp = (*(uintmax_t*)&nb >> 63 == 1) ? -nb : nb;
	tmp2 = tmp;
	str = (*(uintmax_t*)&nb >> 63 == 1) ? ft_strdup("-") : ft_strdup("");
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
		tmp = ft_recup_long(ft_atof(str), nb, i);
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

char	*ft_nan_or_inf(double nb)
{
	if ((*(uintmax_t*)&nb >> 52) % 800 == 0x7FF)
	{
		if (*(uintmax_t*)&nb % 8000000000000 == 0)
		{
			if (*(uintmax_t*)&nb >> 63 == 1)
				return (ft_strdup("-inf"));
			else
				return (ft_strdup("inf"));
		}
		else
			return (ft_strdup("NaN"));
	}
	return (NULL);
}

double	ft_recup(double dif, double nb, int i)
{
	int	j;
	j = 0;
	while (j++ < i)
		dif *= 10;
	return (ABS(nb - dif));
}
char	*ft_itoa_double(double nb, int prec)
{
	char	*str;
	double	tmp;
	double	tmp2;
	int		nbrdig;
	int		i;
		
	if ((str = ft_nan_or_inf(nb)))
		return (str);
	nbrdig = 1;
	tmp = (*(uintmax_t*)&nb >> 63 == 1) ? -nb : nb;
	tmp2 = tmp;
	str = (*(uintmax_t*)&nb >> 63 == 1) ? ft_strdup("-") : ft_strdup("");
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
		tmp = ft_recup(ft_atof(str), nb, i);
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
