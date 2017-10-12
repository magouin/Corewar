/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_borders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 20:00:38 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/14 20:01:13 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	draw_borders(WINDOW *vin)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	j = 0;
	getmaxyx(vin, y, x);
	wattron(vin, COLOR_PAIR(3));
	while (i < y)
	{
		mvwprintw(vin, i, 0, " ");
		mvwprintw(vin, i, x - 1, " ");
		i++;
	}
	while (j < x)
	{
		mvwprintw(vin, 0, j, " ");
		mvwprintw(vin, y - 1, j, " ");
		j++;
	}
	wattroff(vin, COLOR_PAIR(3));
}
