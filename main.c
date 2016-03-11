/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:39 by amineau           #+#    #+#             */
/*   Updated: 2016/03/11 18:07:04 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#define FORM "%C\n"

#define ROD 2147483647
#define DBL 0.33
#define FLL -689.015
#define FL -3.23
#define A  L'요'
#include <stdio.h>
#include <wchar.h>

int main()
{
	//void	*p = 1;
	printf("1 : %d\n",printf(FORM, A));
	printf("2 : %d\n",ft_printf(FORM, A));
	return (0);
}
