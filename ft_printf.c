/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:57:28 by amineau           #+#    #+#             */
/*   Updated: 2016/02/26 08:27:37 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int		size;
	char		*pourc;
	char		*res;
	t_format	**lst;
	//	t_format	*tmp;

	lst = (t_format**)ft_memalloc(sizeof(t_format*));
	va_start(ap, format);
	pourc = (char*)format;
	while (pourc)
	{	
		if ((pourc = ft_strchr(pourc, '%')))
		{
			pourc++;
			if (pourc[0] != '%')
			{
				if (!ft_listadd_format(ft_listnew_format(pourc), lst))
					return (-1);
			}
			else
				pourc++;
		}
	}
	res = ft_strnew(0);
	if ((size = ft_algo(*lst, (char*)format, &res, ap)) != -1)
	{
		ft_putstr(res);
		ft_strdel(&res);
	}
	/*	tmp = *lst;
		while (tmp)
		{
		printf("just : %c || sign : %c || conv : %c || width : %d || precision : %d || lenght : %s || type : %c || size : %zu\n",tmp->just, tmp->sign, tmp->conv, tmp->width, tmp->precision, tmp->lenght, tmp->type, tmp->size);
		tmp = tmp->next;
		}*/
	va_end(ap);
	return (size);
}
