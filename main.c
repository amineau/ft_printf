/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:39 by amineau           #+#    #+#             */
/*   Updated: 2016/03/17 19:40:36 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define FORM "%d\n"
//#define A  L"我是一只猫。"
//#define A  L'요'
//#define A -42
#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int x = 0;
	int y = -20;

	printf("ret = %d\n",    printf("%#0**f\n", 13, 10, 2.3));	
	printf("ret = %d\n", ft_printf("%#0**f\n", 13, 10, 2.3));
	return (0);
}
