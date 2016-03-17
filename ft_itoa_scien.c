/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_scien.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:06:46 by amineau           #+#    #+#             */
/*   Updated: 2016/03/17 11:13:19 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_scien(double nb, int prec, char e)
{
	char	*str;
	double	tmp;
	int		dec;
	int		neg;

	dec = 0;
	tmp = (*(uintmax_t*)&nb >> 63 == 1) ? -nb : nb;
	neg = (*(uintmax_t*)&nb >> 63 == 1) ? 1 : 0;
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
