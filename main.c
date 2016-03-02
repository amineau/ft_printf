/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:39 by amineau           #+#    #+#             */
/*   Updated: 2016/03/02 21:25:12 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FORM "%3.4d\n"

#define ROD 2147483647
#define INT 345442
#define DBL 0.123986
#define FLL -689.015L
#define FL 689.015
#define A -42
#include <stdio.h>

int main()
{
//	double nb = FL;
//	void	*p;
	printf("1 : %d\n",printf(FORM, A));
	printf("2 : %d\n",ft_printf(FORM, A));
//ft_printf("%#jX\n",*(uintmax_t*)&nb);
   //printf("%#jX\n",*(uintmax_t*)&nb);
	return (0);
}
