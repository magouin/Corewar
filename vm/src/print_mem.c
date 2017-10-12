/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:01:45 by magouin           #+#    #+#             */
/*   Updated: 2016/06/15 13:11:51 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_hex(unsigned char c)
{
	if (c / 16 < 10)
		ft_putnbr(c / 16);
	else
		ft_putchar('a' + (c / 16 - 10));
	if (c % 16 < 10)
		ft_putnbr(c % 16);
	else
		ft_putchar('a' + (c % 16 - 10));
}

int		ft_sqrt(int c)
{
	int x;

	x = 0;
	while (x * x < c)
		x++;
	return (x);
}

void	ft_print_mem(unsigned char *str)
{
	int		x;

	x = 0;
	while (x < MEM_SIZE)
	{
		print_hex(str[x]);
		ft_putchar(' ');
		if ((x + 1) % ft_sqrt(MEM_SIZE) == 0)
			ft_putchar('\n');
		x++;
	}
	ft_putstr("\n\n");
}
