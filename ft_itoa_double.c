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
	int	tmp;
	int64_t in64;
	if (prec < 0)
		return (NULL);
	//	printf("ici ca passe\n");
	in64 = nb * ft_power(prec, 10);
	str = ft_strjoin(".",ft_itoa(in64));
	/*
	   str = ft_strnew(prec + 1);
	   i = 0;
	   str[i++] = '.';
	   printf("nb : %.8f\n",nb);
	   nb = ft_arrondi_double(nb, prec);
	   printf("nb : %.8f\n",nb);
	   while (prec != 0)
	   {
	   nb *= 10;
	   printf("nb : %.20f || tmp : %d\n",nb, (int)nb);
	   if (prec != 1)
	   str[i++] = (int)nb + 48;
	   else
	   str[i++] = ft_arrondi(nb) + 48;

	   nb = (nb - (int)nb);
	//	printf("nb : %.2f\n",nb);
	prec--;
	}
	str[i] = '\0';*/
	return (str);
}

char	*ft_integer(double nb, char *str, int nbrdig, int prec)
{
	int		i;
	double	tmp;

	str = ft_strnew(nbrdig);
	tmp = 0;
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

double	ft_atoi_double(char *str)
{
	double	nb;
	int	size;
	int	i;

	size = ft_strlen(str);
	i = (str[0] == '-') ? 1 : 0;
	nb = 0;
	while (i < size)
		nb = nb * 10 + str[i++] - 48;	
	nb = (str[0] == '-') ? -nb : nb;
	return (nb);
}

char	*ft_itoa_double(double nb, int prec)
{
	char	*str;
	double	tmp;
	double	tmp2;
	int		nbrdig;
	int		nbrdig2;
	char	*dest;

	//	printf("nb : %.20f\n",nb);
	nbrdig = 1;
	tmp = (*(uintmax_t*)&nb > DBL_MAX / 2) ? ft_arrondi_double(-nb, prec) : ft_arrondi_double(nb, prec);
	tmp2 = tmp;
	str = (*(uintmax_t*)&nb > DBL_MAX / 2) ? ft_strdup("-") : ft_strdup("");
	//	printf("tmp : %.20f\n",tmp);
	while (tmp > 10)
	{
		tmp /= 10;
		nbrdig++;
	}
	if (nbrdig < 9)
	{
		tmp = (prec < 1) ? ft_arrondi_double(tmp, nbrdig - 1) : tmp;
		str = ft_strclnjoin(str, ft_integer(tmp, str, nbrdig, prec));
		//	printf("nb : %.20f || ft_digit : %.20f\n",nb, ft_digit(tmp, nbrdig));
		//	printf("nb : %.20f\n",nb - ft_digit(tmp, nbrdig));
		str = ft_strcln1join(str, ft_decimal(nb - ft_digit(tmp, nbrdig), prec));
	}
	else
	{
		str = ft_strclnjoin(str, ft_integer(tmp, str, nbrdig - 8, 1));
		//printf("\n%s\n\n",str);
		nbrdig2 = 1;
		tmp = tmp2;
		tmp -= (intmax_t)(tmp / ft_power(8, 10)) * ft_power(8, 10);
		while (nbrdig2 < 8)
		{
			tmp /= 10;
			nbrdig2++;
		}
		tmp = (prec < 1) ? ft_arrondi_double(tmp, nbrdig2 - 1) : tmp;
		str = ft_strclnjoin(str, ft_integer(tmp, str, nbrdig2, prec));
		//printf("\n%s\n\n",str);
		//	printf("nb : %f\natoi : %f\n",nb, ft_atoi_double(str));
		//	printf("abs : %f\n",ABS(nb - ft_atoi_double(str)));
		//	printf("ft_decimal%s\n",ft_decimal(ABS(nb - ft_atoi_double(str)),prec));
		str = ft_strcln1join(str, ft_decimal(ABS(nb - ft_atoi_double(str)), prec));
	}
	return (str);
}
