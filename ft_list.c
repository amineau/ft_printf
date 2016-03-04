/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:33:15 by amineau           #+#    #+#             */
/*   Updated: 2016/03/03 20:18:29 by amineau          ###   ########.fr       */
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
	while (str[i] || str[i] == '%')
	{
		j = 0;
		while (type[j] && type[j] != str[i])
			j++;
		if (type[j])
			return (++i);
		i++;
	}
	return (0);
}

t_format	*ft_listnew_format(char *pourc)
{
	t_format	*list;
	char		*tmp;

	tmp = pourc;
	list = (t_format*)ft_memalloc(sizeof(t_format));
//	if ((list->size = size_format(pourc)) == 0)
//		return (NULL);
	pourc = stock_flag(list, pourc);
	pourc = stock_width(&list->width, pourc);
	pourc = stock_precision(&list->precision, pourc, list->width);
	pourc = stock_lenght(&list->lenght, pourc);
		list->type = *pourc;
		list->size = 1;
	while (ft_strcmp(pourc, tmp++))
		list->size++;
	if (pourc[0])	
	list->size++;
	if (list->precision == -2 && ft_strchr("eEfFgG",list->type))
		list->precision = 6;
	else if (list->precision == -2 && ft_strchr("dioux",list->type))
		list->precision = 1;
	return (list);
}

int		ft_listadd_format(t_format *list, t_format **begin)
{
	t_format	*tmp;

	if (!list)
		return (0);
	if ((tmp = *begin))
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list;
	}
	else
		*begin = list;
	return (1);
}
