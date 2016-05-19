/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:01:45 by magouin           #+#    #+#             */
/*   Updated: 2016/05/19 13:01:46 by magouin          ###   ########.fr       */
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
	ft_putchar(' ');
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
	//ft_putstr("\033[2J\033[1,1H");
	while (x < MEM_SIZE)
	{
		print_hex(str[x]);
		if ((x + 1) % ft_sqrt(MEM_SIZE) == 0)
			ft_putchar('\n');
		x++;
	}
}
