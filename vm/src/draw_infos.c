/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 20:02:20 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/14 20:04:49 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		get_process_nb(t_env *env)
{
	t_process	*process;
	int			cpt;

	cpt = 0;
	process = (t_process *)env->process;
	while (process)
	{
		cpt++;
		process = process->next;
	}
	return (cpt);
}

static t_player	*find_last_live(t_env *env)
{
	t_player	*players;

	players = (t_player *)env->player;
	while (players)
	{
		if (players->nbr == env->live)
			return (players);
		players = players->next;
	}
	return (NULL);
}

void			draw_infos(WINDOW *vin, t_env *env, t_loop *loop_params)
{
	t_player	*last_live_player;
	char		*player;

	wattron(vin, COLOR_PAIR(4));
	last_live_player = find_last_live(env);
	(void)env;
	mvwprintw(vin, 2, 2, "GAME INFOS");
	mvwprintw(vin, 6, 2, ft_strjoin("Cycle : "
				, ft_itoa(loop_params->total_cycle)));
	mvwprintw(vin, 8, 2, ft_strjoin(ft_strjoin("Processes : "
					, ft_itoa(get_process_nb(env))), "     "));
	player = "NULL";
	if (last_live_player)
	{
		player = ft_strjoin("Last live : ", last_live_player->name);
		player = ft_strjoin(player, "                             ");
	}
	mvwprintw(vin, 11, 2, player);
	mvwprintw(vin, 14, 2, ft_strjoin(ft_strjoin("CYCLE_TO_DIE : "
					, ft_itoa(loop_params->cycle_to_die)), "  "));
	mvwprintw(vin, 16, 2, ft_strjoin("CYCLE_DELTA : ", ft_itoa(CYCLE_DELTA)));
	mvwprintw(vin, 18, 2, ft_strjoin("NBR_LIVE : ", ft_itoa(NBR_LIVE)));
	mvwprintw(vin, 20, 2, ft_strjoin("MAX_CHECKS : ", ft_itoa(MAX_CHECKS)));
	wrefresh(vin);
	wattroff(vin, COLOR_PAIR(4));
}
