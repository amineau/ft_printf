/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:08 by amineau           #+#    #+#             */
/*   Updated: 2016/02/25 18:36:40 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"
#include <stdio.h>
typedef struct	s_format
{
	char			just;
	char			sign;
	char			conv;
	int				width;
	int				precision;
	char			*lenght;
	char			type;
	struct s_format	*next;
}				t_format;

int			ft_printf(const char *format, ...);
char		*stock_flag(t_format *lst, char *str);
char		*stock_width(int *width, char *pourc);
char		*stock_precision(int *prec, char *pourc);
char		*stock_lenght(char **str, char *pourc);
t_format	*ft_listnew_format(char *pourc);
void		ft_listadd_format(t_format *list, t_format **begin);
void		ft_error(void);
#endif
