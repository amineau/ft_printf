/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:18:47 by amineau           #+#    #+#             */
/*   Updated: 2016/03/14 17:35:01 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_wcharlen(wchar_t *w)
{
	unsigned int	i;

	i = 0;
	while (w[i])
		i++;
	return (i);
}

int	*ft_cntwchar(wchar_t **w, int prec)
{
	int i;
	int	size;
	int	*t;
	int	sum;

	i = 0;
	size = ft_wcharlen(*w);
	sum = 0;
	if (!(t = (int*)malloc(sizeof(int) * (size + 1))))
		return (0);
	while ((*w)[i] && (prec >= sum || prec < 0))
	{
		t[i] = ft_cntwint((*w)[i]);
		sum += t[i++];
	}
	if (sum > prec && prec >= 0)
		i--;
	t[i] = 0;
	return (t);
}

int		ft_sum(int *t)
{
	int i;
	int	sum;

	i = 0;
	sum = 0;
	while (t[i])
		sum += t[i++];
	return (sum);
}

void	ft_put(wchar_t *w, int *t)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
		while (w[i] && sum <= ft_sum(t))
		{
			ft_putwint(w[i], t[i]);
			sum += t[i++];
		}
}

int		ft_putwchar(wchar_t *w, t_format *lst)
{
	int		size;
	int		*t;
	char	*str;

	str = NULL;
	t = ft_cntwchar(&w, lst->precision);
	size = ft_sum(t);
	if (lst->width <= size)
		ft_put(w, t);
	else if (lst->just == '-')
	{
		ft_put(w, t);
		ft_putstr(str = ft_wh(' ', lst->width - size));
	}
	else
	{
		ft_putstr(str = ft_wh(lst->just, lst->width - size));
		ft_put(w, t);
	}
	ft_memdel((void**)&t);
	size += ft_strlen(str);
	ft_strdel(&str);
	return (size);
}
