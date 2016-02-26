/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:39 by amineau           #+#    #+#             */
/*   Updated: 2016/02/26 14:05:46 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FORM "%d %s chiffre : %.3f ou %%%U et %#O, %#X %p\n"

#define A 0, "coucou", -0.0, 9, 122, 14
#include <stdio.h>

int main()
{
	void	*p;
	printf("1 : %d\n",printf(FORM, A, p));
	printf("2 : %d\n",ft_printf(FORM, A, p));
	return (0);
}
