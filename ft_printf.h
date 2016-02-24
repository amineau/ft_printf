#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_format
{
	char		flag;
	char		*width;
	char		*precision;
	char		*lenght;
	char		type;
	va_list		ap;
	struct s_format	*next;
}		t_format;

int	ft_printf(const char *format, ...);

#endif
