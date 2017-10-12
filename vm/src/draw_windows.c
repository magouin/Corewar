/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 17:24:32 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/14 22:34:21 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	has_process(t_env *env, int index)
{
	t_process	*process;

	process = (t_process *)env->process;
	while (process)
	{
		if (process->pc == index)
			return (1);
		process = process->next;
	}
	return (0);
}

static void	init_colors(void)
{
	start_color();
	init_pair(1, 8, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, 15);
	init_pair(3, COLOR_BLACK, 8);
	init_pair(4, 15, COLOR_BLACK);
}

static void	add_color(WINDOW *vin, t_env *env, int i, int j)
{
	if (has_process(env, i * 64 + j))
		wattron(vin, COLOR_PAIR(2));
	else if (env->arena[i * 64 + j] == 0)
		wattron(vin, COLOR_PAIR(1));
	else
		wattron(vin, COLOR_PAIR(4));
}

static void	remove_color(WINDOW *vin)
{
	wattroff(vin, COLOR_PAIR(2));
	wattroff(vin, COLOR_PAIR(1));
	wattroff(vin, COLOR_PAIR(4));
}

void		draw_windows(WINDOW **windows, t_env *env, t_loop *loop_params)
{
	int		i;
	int		j;
	char	*value;

	init_colors();
	draw_infos(windows[1], env, loop_params);
	draw_borders(windows[0]);
	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			add_color(windows[0], env, i, j);
			value = ft_itoa_base(env->arena[i * 64 + j], 16);
			if (ft_strlen(value) == 1)
				value = ft_strjoin("0", value);
			mvwprintw(windows[0], i + 2, j * 3 + 2, value);
			j++;
			remove_color(windows[0]);
		}
		i++;
	}
	wrefresh(windows[0]);
}
