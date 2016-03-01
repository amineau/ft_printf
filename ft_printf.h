/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:08 by amineau           #+#    #+#             */
/*   Updated: 2016/02/28 14:18:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"
/*************config linux************/
#include <stdint.h>
/*************************************/
# define TYPE "sSpdDioOfFuUxXcCbBeE"
# define ABS(x) (((x) < 0) ? -(x) : (x))
# define SHRT_MAX 0x7FFF
# define USHRT_MAX 0xFFFF
# define INT_MAX 0x7FFFFFFF
# define UINT_MAX 0xFFFFFFFF
# define DBL_MAX (double)0xFFFFFFFFFFFFFFFF
# define LDBL_MAX (long double)0xFFFFFFFFFFFFFFFFFFFFL

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
char		*ft_itoa_double(double nb, int prec);
char		*ft_ftoa(float f, int *status);
char		*stock_flag(t_format *lst, char *str);
char		*stock_width(int *width, char *pourc);
char		*stock_precision(int *prec, char *pourc);
char		*stock_lenght(char **str, char *pourc);
char		*ft_straddc(char *str, char c);
t_format	*ft_listnew_format(char *pourc);
int			ft_listadd_format(t_format *list, t_format **begin);
void		ft_lstdel_format(t_format *lst);
int		ft_arrondi(long double nb);
long double	ft_arrondi_double(long double nb, size_t dec);

#endif
