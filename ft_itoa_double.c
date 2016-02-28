/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 11:28:40 by amineau           #+#    #+#             */
/*   Updated: 2016/02/28 14:18:44 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_double(double nb, int prec)
{
	char	*str=NULL;
	double	tmp;
	int		nbrdig;

	nbrdig = 1;
	tmp =  (*(uintmax_t*)&nb > DBL_MAX / 2) ? -nb : nb;
	while (tmp > 10)
		{
			tmp /= 10;
			nbrdig += 1
		}
	while (nbrdig = 0)
	{

	}

	return (str);
}

int main()
{
	double db = 11444444555556432234.123456;
	ft_itoa_double(db, 4);
	printf("%f \n%i\n",DBL_MAX, INT_MAX);
	return (0);
}
