/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:39 by amineau           #+#    #+#             */
/*   Updated: 2016/02/26 04:23:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FORM "%s %s chiffre : %d ou %%%i et %i\n"

#define A "4", "coucou", 45, -90, -2000000000
#include <stdio.h>

int main()
{
	printf("%d\n",printf(FORM, A));
	printf("%d\n",ft_printf(FORM, A));
	return (0);
}
