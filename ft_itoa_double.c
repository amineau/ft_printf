/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 11:28:40 by amineau           #+#    #+#             */
/*   Updated: 2016/03/17 11:23:26 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
