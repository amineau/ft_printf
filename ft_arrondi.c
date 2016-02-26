/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrondi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:17:09 by amineau           #+#    #+#             */
/*   Updated: 2016/02/26 10:32:01 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	arrondi(double nb)
{
	if (nb - (int)nb < 0.5)
		return ((intmax_t)nb);
	else
		return ((intmax_t)(nb + 1));
}
