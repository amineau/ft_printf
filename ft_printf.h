/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:08 by amineau           #+#    #+#             */
/*   Updated: 2016/02/26 17:16:59 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"
# define TYPE "sSpdDioOfFuUxXcCbBeE"
# define ABS(x) (x < 0) ? -x : x
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
	size_t			size;
	struct s_format	*next;
}				t_format;

int			ft_printf(const char *format, ...);
int			ft_algo(t_format *lst, char *str, char **res, va_list ap);
char		*stock_flag(t_format *lst, char *str);
char		*stock_width(int *width, char *pourc);
char		*stock_precision(int *prec, char *pourc);
char		*stock_lenght(char **str, char *pourc);
char		*ft_straddc(char *str, char c);
t_format	*ft_listnew_format(char *pourc);
int			ft_listadd_format(t_format *list, t_format **begin);
void		ft_lstdel_format(t_format *lst);
intmax_t	arrondi(double nb);

#endif
