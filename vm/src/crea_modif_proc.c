/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_modif_proc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 19:13:16 by arobin            #+#    #+#             */
/*   Updated: 2016/06/15 14:55:47 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void			reset_live_proc(t_env *env)
{
	t_process	*tmp;

	tmp = env->process;
	while (tmp != NULL)
	{
		tmp->live = 0;
		tmp = tmp->next;
	}
}

void			verb(t_process *p, int r)
{
	ft_putstr("Process ");
	ft_putnbr(p->num);
	ft_putstr(" has killed (CTD ");
	ft_putnbr(r);
	ft_putstr(")\n");
}

t_process		*create_new_proc(t_player *player)
{
	t_process	*new_p;
	int			x;

	if ((new_p = (t_process *)malloc(sizeof(t_process))) == NULL)
		exit(EXIT_FAILURE);
	new_p->cycle = 0;
	new_p->live = 0;
	new_p->carry = 0;
	new_p->reg = malloc(sizeof(int*) * REG_NUMBER);
	x = 0;
	while (x < REG_NUMBER)
	{
		new_p->reg[x] = 0;
		x++;
	}
	new_p->reg[0] = player->nbr;
	return (new_p);
}

void			set_up_proc(t_process *f_proc, t_player *f_player)
{
	t_player	*player_tmp;
	t_process	*proc_tmp;
	int			i;

	player_tmp = f_player;
	proc_tmp = f_proc;
	i = count_champ(f_player) - 1;
	proc_tmp->pc = 0;
	while (proc_tmp->next != NULL)
	{
		proc_tmp->pc = MEM_SIZE / count_champ(f_player) * i;
		proc_tmp = proc_tmp->next;
		i--;
	}
	proc_tmp->pc = MEM_SIZE / count_champ(f_player) * i;
}

t_process		*create_proc(t_env *env)
{
	t_player	*player_tmp;
	t_process	*proc_tmp;
	t_process	*f_proc;

	f_proc = NULL;
	player_tmp = env->player;
	while (player_tmp)
	{
		proc_tmp = create_new_proc(player_tmp);
		proc_tmp->next = f_proc;
		proc_tmp->num = ++(env->num_last_process);
		f_proc = proc_tmp;
		player_tmp = player_tmp->next;
	}
	set_up_proc(f_proc, env->player);
	return (f_proc);
}
