/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:18:47 by amineau           #+#    #+#             */
/*   Updated: 2016/03/11 18:06:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_cntwchar(wchar_t *w)
{
	int 			i;
	int				size;
	unsigned int	*t;

	i = -1;
	size = ft_strlen(w);
	if (!(t = (unsigned int*)malloc(sizeof(unsigned int) *size)))
		return (0);
	while (w[++i])
		t[i] = (unsigned int)w[i];
	return (t);
}

int		ft_count(int *t)
{
	int i;
}

void	ft_putwchar(wchar_t *w, int *t)
{
	int i;

	i = -1;
	while (w[++i])
		ft_putwint(w[i], t[i]);
	free(&t);
}
