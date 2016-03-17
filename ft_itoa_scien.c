/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_scien.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:06:46 by amineau           #+#    #+#             */
/*   Updated: 2016/03/17 19:37:02 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_scien(double nb, int prec, char e)
{
	char	*str;
	double	tmp;
	int		dec;
	int		neg;

	if ((str = ft_nan_or_inf(nb, e)))
		return (str);
	dec = 0;
	tmp = (*(uintmax_t*)&nb >> 63 == 1) ? -nb : nb;
	neg = (*(uintmax_t*)&nb >> 63 == 1) ? 1 : 0;
	str = ft_strnew(neg + 1);
	str[0] = '-';
	while (tmp < 1 && dec-- <= 0)
		tmp *= 10;
	while (tmp >= 10)
	{
		tmp /= 10;
		dec++;
	}
	str = ft_itoa_double(tmp, prec, e);
	str = ft_strclnjoin(str, ft_exposant(e, dec));
	return (str);
}
