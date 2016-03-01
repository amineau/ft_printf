/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:39 by amineau           #+#    #+#             */
/*   Updated: 2016/02/28 19:43:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FORM "%.20f \n"

#define MAXINT 2147483647
#define INT 42
#define FL 0XFFFFFFFFFFFFFFFF
#define FLL 689.015L
#define A FL
#include <stdio.h>

int main()
{
	double nb = FL;
//	void	*p;
//	printf("1 : %d\n",printf(FORM, A));
//	printf("2 : %d\n",ft_printf(FORM, A));
ft_printf("%#X\n",*(float*)&nb);
   printf("%#X\n",*(float*)&nb);
	return (0);
}
