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

#define FORM "% 08d %.f %03u %o %05x %.3s\n"

#define MAXINT 2147483647
#define INT 42
#define FL 6880889.015
#define FLL 689.015L
#define A -INT, FL, INT, -INT, INT
#include <stdio.h>

int main()
{
//	void	*p;
	char *str=NULL;
	printf("1 : %d\n",printf(FORM, A, str));
	printf("2 : %d\n",ft_printf(FORM, A,str));
	return (0);
}
