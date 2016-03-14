/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:39 by amineau           #+#    #+#             */
/*   Updated: 2016/03/14 20:24:46 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define FORM "{%f}\n"
#define ROD 2147483647
#define DBL 0.33
#define FLL -689.015
#define FL -3.23
//#define A  L"我是一只猫。"
//#define A  L'요'
#define A 
#include <stdio.h>

int main()
{
	void	*p;
	printf("1 : %d\n",printf(FORM, A));
	printf("2 : %d\n",ft_printf(FORM, A));
	return (0);
}
