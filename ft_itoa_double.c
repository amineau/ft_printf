/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 11:28:40 by amineau           #+#    #+#             */
/*   Updated: 2016/02/28 23:20:23 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_decimal(double nb, int prec)
{
	char	*str;
	int		i;

	if (prec < 0)
		return (NULL);
	str = ft_strnew(prec + 1);
	i = 0;
	str[i++] = '.';
	while (prec != 0)
	{
		nb *= 10;
		if (prec != 1)
		str[i++] = (int)nb + 48;
		else
		str[i++] = arrondi(nb) + 48;
		nb = (nb - (int)nb);
		prec--;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_integer(double nb, char *str, int nbrdig)
{
	int		i;
	double	tmp;

	str = ft_strnew(nbrdig);
	tmp = 0;
	i = 0;
	while (nbrdig != 0)
	{
		if (nbrdig != 1)
		str[i++] = (int)nb + 48;
		else
		str[i++] = arrondi(nb) + 48;
		nb = (nb - (int)nb) * 10;
		nbrdig--;
	}
	str[i] = '\0';
	return (str);
}

double	ft_digit(double nb, int nbrdig)
{
	double	res;

	res = 0;
	while (nbrdig != 0)
	{ 
		res = res * 10 + (int)nb;
		nb = (nb - (int)nb) * 10;
		nbrdig--;
	}
	return (res);
}

char	*ft_itoa_double(double nb, int prec)
{
	char	*str;
	double	tmp;
	double	tmp2;
	int		nbrdig;
	int		nbrdig2;
	char	*dest;

	nbrdig = 1;
	tmp = (*(uintmax_t*)&nb > DBL_MAX / 2) ? -nb : nb;
	tmp2 = tmp;
	str = (*(uintmax_t*)&nb > DBL_MAX / 2) ? ft_strdup("-") : ft_strdup("");
	while (tmp > 10)
	{
		tmp /= 10;
		nbrdig++;
	}
	if (nbrdig < 13)
	{
		str = ft_strclnjoin(str, ft_integer(tmp, str, nbrdig));
		str = ft_strcln1join(str, ft_decimal(nb - ft_digit(tmp, nbrdig), prec));
	}
	else
	{
		str = ft_strclnjoin(str, ft_integer(tmp, str, nbrdig - 12));
		nbrdig2 = 1;
		tmp = tmp2;
		tmp -= (intmax_t)(tmp / ft_power(12, 10)) * ft_power(12, 10);
		while (nbrdig2 < 12)
		{
			tmp /= 10;
			nbrdig2++;
		}
		str = ft_strclnjoin(str, ft_integer(tmp, str, nbrdig2));
		str = ft_strcln1join(str, ft_decimal(nb - ft_digit(tmp, nbrdig + nbrdig2), prec));
	}
	return (str);
}

int main()
{
	double db = 1234567890120.123456789012;
	printf("%#.15f \n%s\n",db, ft_itoa_double(db, 15));
	return (0);
}
