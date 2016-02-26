/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:39 by amineau           #+#    #+#             */
/*   Updated: 2016/02/26 07:22:34 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FORM "%s %s chiffre : %d ou %%%i et %o, %#X %p\n"

#define A "4", "coucou", 45, -90, 122, 14
#include <stdio.h>

int main()
{
	void	*p;
	printf("%d\n",printf(FORM, A, p));
	printf("%d\n",ft_printf(FORM, A, p));
	return (0);
}
