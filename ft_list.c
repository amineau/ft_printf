/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:33:15 by amineau           #+#    #+#             */
/*   Updated: 2016/02/26 02:55:28 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstdel_format(t_format *lst)
{
	if (lst->lenght)
		ft_strdel(&lst->lenght);
	free(lst);
}

int			size_format(char *str)
{
	int 	i;
	int		j;
	char	*type;

	type = TYPE;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (type[j] && type[j] != str[i])
			j++;
		if (type[j])
			return (++i);
		i++;
	}
	ft_error();
	return (0);
}

t_format	*ft_listnew_format(char *pourc)
{
	t_format	*list;

	list = (t_format*)ft_memalloc(sizeof(t_format));
	list->size = size_format(pourc);
	pourc = stock_flag(list, pourc);
	pourc = stock_width(&list->width, pourc);
	pourc = stock_precision(&list->precision, pourc);
	pourc = stock_lenght(&list->lenght, pourc);
	if (ft_strchr(TYPE, *pourc))
		list->type = *pourc;
	else
		ft_error();
	list->size++;
	if (list->precision == -2 && ft_strchr("eEf",list->type))
		list->precision = 6;
	else if (list->precision == -2 && ft_strchr("dioux",list->type))
		list->precision = 1;
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
