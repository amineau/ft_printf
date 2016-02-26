/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:39 by amineau           #+#    #+#             */
/*   Updated: 2016/02/26 17:16:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FORM "%d %8s chiffre : %7.3f ou %%%03U et %#O, %#-5X %E %p\n"

#define A 0, "coucou", 0.0, 9, 122, 14, 4.3455
#include <stdio.h>

int main()
{
	void	*p;
	printf("1 : %d\n",printf(FORM, A, p));
	printf("2 : %d\n",ft_printf(FORM, A, p));
	return (0);
}
