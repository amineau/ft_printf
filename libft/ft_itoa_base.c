/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:50:53 by amineau           #+#    #+#             */
/*   Updated: 2016/02/25 18:16:41 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nbrdigit(unsigned int nbr, int base)
{
	int pow;

	pow = 0;
	while (nbr / base != 0)
	{
		nbr = nbr / base;
		pow++;
	}
	return (pow + 1);
}

int		power(int nbr, int base)
{
	int i;
	int res;

	i = 0;
	res = 1;
	while (i++ < nbr)
		res *= base;
	return (res);
}

int		bo(int digit, unsigned int tmp, int i, char *str)
{
	if (digit < 10)
		str[i] = digit + 48;
	else
		str[i] = digit + 55;
	return (tmp);
}

char	*ft_itoa_base(int value, int base)
{
	char			*str;
	int				neg;
	int				pow;
	int				i;
	unsigned int	tmp;

	i = 0;
	neg = (value < 0) ? 1 : 0;
	tmp = (value < 0) ? -value : value;
	pow = nbrdigit(tmp, base);
	str = (char*)malloc(sizeof(char) * (neg + pow + 1));
	if (neg == 1)
		str[i++] = '-';
	while (--pow >= 0)
		tmp = bo(tmp / power(pow, base), tmp % power(pow, base), i++, str);
	str[i] = '\0';
	return (str);
}
