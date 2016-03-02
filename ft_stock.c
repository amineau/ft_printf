/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:33:37 by amineau           #+#    #+#             */
/*   Updated: 2016/03/02 21:25:08 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*stock_digit(int *nb, char *pourc)
{
	int i;

	i = 0;
	while (ft_isdigit(pourc[i]))
		i++;
	*nb = ft_atoi(pourc);
	return(pourc + i);		
}

char		*stock_flag(t_format *lst, char *str)
{
	int		i;

	i = 0;
	while (str[i] == '0' || str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '#')
		i++;
	if (ft_strnchr(str, '-', i)) 
		lst->just = '-';
	else if (ft_strnchr(str, '0', i))
		lst->just = '0';
	else
		lst->just = ' ';
	if (ft_strnchr(str, '+', i))
		lst->sign = '+';
	else if (ft_strnchr(str, ' ', i))
		lst->sign = ' ';
	else
		lst->sign = 0;
	lst->conv = (ft_strnchr(str, '#', i)) ? '#' : 0;
	if ((ft_strnchr(str, '+', i) && ft_strnchr(str, ' ', i)) || (ft_strnchr(str, '-', i) && ft_strnchr(str, '0', i)))
		return (NULL);
	return (&str[i]);
}

char		*stock_width(int *width, char *pourc)
{
	if (ft_isdigit(pourc[0]))
		pourc = stock_digit(width, pourc);	
	else if (pourc[0] == '*')
	{
		*width = -1;
		pourc++;
	}
	else
		*width = 0;
	return (pourc);
}

char		*stock_precision(int *prec, char *pourc)
{
	if (pourc[0] == '.' && pourc[1] != '*')
		pourc = stock_digit(prec, &pourc[1]);
	else if (pourc[1] == '*')
	{
		*prec = -1;
		pourc += 2;
	}
	else
		*prec = -2;
	return (pourc);
}

char		*stock_lenght(char **str, char *pourc)
{
	if ((pourc[0] == 'h' && pourc[1] == 'h') || (pourc[0] == 'l' && pourc[1] == 'l'))
	{
		*str = ft_strndup(pourc, 2);
		pourc += 2;
	}
	else if (pourc[0] == 'h' || pourc[0] == 'l' || pourc[0] == 'j' || pourc[0] == 'z' || pourc[0] == 'L')
	{		
		*str = ft_strndup(pourc, 1);
		pourc++;
	}
	else
		*str = ft_strnew(0);
	return (pourc);
}
