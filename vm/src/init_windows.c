/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 20:46:45 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/09 17:50:25 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

WINDOW	**init_windows(void)
{
	WINDOW		**windows;
	int			parent_x;
	int			parent_y;

	if (!(windows = malloc(sizeof(WINDOW *) * 2)))
		exit(0);
	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	getmaxyx(stdscr, parent_y, parent_x);
	windows[0] = newwin(64 + 4, 192 + 4, 0, 0);
	windows[1] = newwin(64, 50, 0, 192 + 4);
	wtimeout(windows[0], 1);
	wtimeout(windows[1], 1);
	return (windows);
}
