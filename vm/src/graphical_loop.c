/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 21:03:09 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/14 20:07:10 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	static_loop(t_loop *loop_params, t_env *env, WINDOW **windows)
{
	int	sleep_time;
	int	chr;
	int	game_paused;

	game_paused = 1;
	sleep_time = 10000;
	while (env->process != NULL)
	{
		chr = wgetch(windows[0]);
		if (chr == ' ')
			game_paused = game_paused ^ 1;
		else if (chr == 't')
			sleep_time = (sleep_time - 1000 < 0) ? 0 : sleep_time - 1000;
		else if (chr == 'r')
			sleep_time = (sleep_time + 1000 > 100000)
				? 100000 : sleep_time + 1000;
		if (game_paused == 0 || chr == 's')
		{
			inside_loop(loop_params, env);
			draw_windows(windows, env, loop_params);
		}
		chr = 0;
		usleep(sleep_time);
	}
}

void		graphical_loop(t_env *env)
{
	WINDOW	**windows;
	int		chr;
	t_loop	*loop_params;

	loop_params = init_loop_params();
	env->process = create_proc(env);
	windows = init_windows();
	draw_windows(windows, env, loop_params);
	while (env->process != NULL)
	{
		static_loop(loop_params, env, windows);
	}
	while (1)
	{
		chr = wgetch(windows[0]);
		if (chr == 'p')
		{
			delwin(windows[0]);
			delwin(windows[1]);
			endwin();
			exit(0);
		}
	}
}
