/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 20:25:46 by magouin           #+#    #+#             */
/*   Updated: 2016/06/14 20:25:47 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void			ft_printverb(t_env *env)
{
	t_player *p;

	p = env->player;
	ft_putstr("Introducing contestants...\n");
	while (p)
	{
		ft_putstr("* Player ");
		ft_putnbr(-1 * p->nbr);
		ft_putstr(", weighing ");
		ft_putnbr(p->len_prog);
		ft_putstr(" bytes, \"");
		ft_putstr(p->name);
		ft_putstr("\" (\"");
		ft_putstr(p->comment);
		ft_putstr("\") !\n");
		p = p->next;
	}
}

void			free_all(t_env *env, t_loop *loop)
{
	t_player *p;

	(void)loop;
	p = env->player->next;
	while (env->player)
	{
		free(env->player->name);
		free(env->player->comment);
		free(env->player->prog);
		free(env->player);
		env->player = p;
		env->player ? p = env->player->next : 0;
	}
	free(env->flags->verbose);
	free(env->flags);
	free(env->arena);
	free(env);
	free(loop);
}

void			loop(t_env *env)
{
	t_loop		*loop_params;
	t_player	*p;

	ft_printverb(env);
	env->live = env->player->nbr;
	loop_params = init_loop_params();
	env->process = create_proc(env);
	while (env->process != NULL)
		inside_loop(loop_params, env);
	p = env->player;
	while (p->nbr != env->live)
		p = p->next;
	ft_putstr("Contestant ");
	ft_putnbr(-1 * p->nbr);
	ft_putstr(", \"");
	ft_putstr(p->name);
	ft_putstr("\", has won !\n");
	free_all(env, loop_params);
}
