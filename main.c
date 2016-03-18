/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:39 by amineau           #+#    #+#             */
/*   Updated: 2016/03/18 18:39:34 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define A  L"我是一只猫。"
//#define A  L'요'
#define FORM "%d\n"
#define A -42
#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <fcntl.h>

int main()
{
	int x = 0;
	int y = -20;
	char *s = ft_strjoin("hgfsjkghjs", NULL);
	char* l = setlocale(LC_ALL, "");

	printf("ret = %d\n", printf("%#x\n", -1));
	printf("ret = %d\n", ft_printf("%#x\n", -1));
	return (0);
}
