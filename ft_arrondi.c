/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrondi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:17:09 by amineau           #+#    #+#             */
/*   Updated: 2016/02/27 20:46:16 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	arrondi(long double nb)
{
	long double tmp;
	int			neg;

	tmp = (nb < 0) ? -nb : nb;
	neg = (nb < 0) ? -1 : 1;
	if (tmp - (intmax_t)tmp < 0.5)
		return ((intmax_t)nb);
	return ((intmax_t)(nb + neg));
}

long double	arrondi_double(long double nb, size_t dec)
{
	long double tmp;
	int			neg;
	uintmax_t	pow;
	intmax_t	tmp_int;

	pow = ft_power(dec, 10);
	tmp = (nb < 0) ? -nb * pow : nb * pow ;
	neg = (nb < 0) ? -1 : 1;
	tmp_int = tmp;
	if (tmp - (intmax_t)tmp < 0.5)
		return ((long double)tmp_int * neg / pow);
	return ((long double)(tmp_int + 1) * neg / pow);
}
