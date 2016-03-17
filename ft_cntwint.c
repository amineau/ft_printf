/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntwint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:14:33 by amineau           #+#    #+#             */
/*   Updated: 2016/03/16 16:15:32 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cntwint(unsigned int w)
{
	if (w < 0x80)
		return (1);
	if (w < 0x800)
		return (2);
	if (w < 0x10000)
		return (3);
	if (w < 0x200000)
		return (4);
	return (-1);
}
