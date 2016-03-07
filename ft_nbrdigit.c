#include "ft_printf.h"

int		nbrdigit(uintmax_t nb)
{
	int pow;

	pow = 0;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		pow++;
	}
	return (pow);
}
