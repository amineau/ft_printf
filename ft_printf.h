/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:08 by amineau           #+#    #+#             */
/*   Updated: 2016/03/17 11:20:25 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft/libft.h"
# define TYPE "sSpdDioOfFuUxXcCbBeE"
# define ABS(x) (((x) < 0) ? -(x) : (x))
# define SHRT_MAX 0x7FFF
# define USHRT_MAX 0xFFFF
# define INT_MAX 0x7FFFFFFF
# define LONG_MAX (long)0x7FFFFFFFFFFF
# define UINT_MAX 0xFFFFFFFF
# define DBL_MAX (double)0xFFFFFFFFFFFFFFFF
# define LDBL_MAX (long double)0xFFFFFFFFFFFFFFFFFFFF

#include <stdio.h>
typedef struct	s_format
{
	char			just;
	char			sign;
	char			conv;
	int				width;
	int				wild_width;
	int				precision;
	char			*lenght;
	char			type;
	size_t			size;
	struct s_format	*next;
}				t_format;

int				ft_printf(const char *format, ...);
int				ft_algo(t_format *lst, char *str, va_list ap);
char			*ft_itoa_double(double nb, int prec);
char			*ft_itoa_scien(double nb, int prec, char c);
char			*ft_itoa_long(long double nb, int prec);
char			*ft_itoa_scien_long(long double nb, int prec, char c);
char			*stock_flag(t_format *lst, char *str);
char			*stock_width(int *width, int *wild,char *pourc);
char			*stock_precision(int *prec, char *pourc, int width);
char			*stock_lenght(char **str, char *pourc);
char			*ft_straddc(char *str, char c);
char			*ft_wh(char c, int n);
char			*ft_decimal(long double nb, int prec);
char			*ft_exposant(char e, int dec);
t_format		*ft_listnew_format(char *pourc);
int				ft_listadd_format(t_format *list, t_format **begin);
int				nbrdigit(uintmax_t nb);
int				ft_cntwint(unsigned int w);
char			*ft_decimal(long double nb, int prec);
char			*ft_integer(long double nb, char *str, int nbrdig, int prec);
void			ft_refresh(char **str);
char			*ft_exposant(char e, int dec);
void			ft_putwint(unsigned int w, int oc);
void			ft_refresh(char **str);
int				ft_putwchar(wchar_t *w, t_format *lst);
void			ft_lstdel_format(t_format *lst);
int				ft_arrondi(long double nb);
long double		ft_arrondi_double(long double nb, size_t dec);
long double		ft_atof(char *str);
unsigned int	ft_wcharlen(wchar_t *w);
wchar_t			*ft_wcharndup(wchar_t *s1, size_t n);

#endif
