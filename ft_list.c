/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:33:15 by amineau           #+#    #+#             */
/*   Updated: 2016/02/25 16:42:41 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_listnew_format(char *pourc)
{
	t_format	*list;

	list = (t_format*)ft_memalloc(sizeof(t_format));
	pourc = stock_flag(list, pourc);
	pourc = stock_width(&list->width, pourc);
	pourc = stock_precision(&list->precision, pourc);
	pourc = stock_lenght(&list->lenght, pourc);
	if (ft_strchr("sSpdDioOuUxXcC", *pourc))
		list->type = *pourc;
	else
		ft_error();
	return (list);
}

void		ft_listadd_format(t_format *list, t_format **begin)
{
	t_format	*tmp;

	if ((tmp = *begin))
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list;
	}
	else
		*begin = list;
}
