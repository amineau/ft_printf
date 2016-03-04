/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:39 by amineau           #+#    #+#             */
/*   Updated: 2016/03/03 21:03:12 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#define FORM "%*.*d\n"

#define ROD 2147483647
#define DBL 0.33
#define FLL -689.015
#define FL -3.23
#define A  3, 10, 42
#include <stdio.h>

int main()
{
//	double nb = FL;
	void	*p = 1;
	int	*n;
	printf("1 : %d\n",printf(FORM, A));
	printf("2 : %d\n",ft_printf(FORM, A));
//ft_printf("%#jX\n",*(uintmax_t*)&nb);
   //printf("%#jX\n",*(uintmax_t*)&nb);
	return (0);
}
