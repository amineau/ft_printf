/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:39 by amineau           #+#    #+#             */
/*   Updated: 2016/02/27 23:09:06 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FORM "% 08d %.10f %03u %05o %05x %.3s\n"

#define MAXINT 2147483647
#define INT 42
#define FL 6888889.0145
#define A -INT, FL, INT, INT, INT
#include <stdio.h>

int main()
{
//	void	*p;
	char *str=NULL;
	printf("1 : %d\n",printf(FORM, A, str));
	printf("2 : %d\n",ft_printf(FORM, A,str));
	return (0);
}
