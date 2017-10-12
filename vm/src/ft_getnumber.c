/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:41:27 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/10 18:29:25 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_getnumber(unsigned char *str, int ptr, int size)
{
	size_t	rez;
	int		x;

	x = 0;
	rez = 0;
	while (x < size)
	{
		rez = rez * 256 + str[ft_mod((ptr + x) % MEM_SIZE)];
		x++;
	}
	return (rez);
}
