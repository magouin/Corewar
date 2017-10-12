/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:54:55 by magouin           #+#    #+#             */
/*   Updated: 2016/06/15 15:09:14 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void			exe_proc(t_env *env, t_process *proc_to_exe)
{
	int			pc;
	int			op_code;

	if (proc_to_exe->cycle == 1)
	{
		pc = proc_to_exe->pc;
		op_code = proc_to_exe->op;
		if (ft_exec_operations(env, proc_to_exe) == 0)
			proc_to_exe->pc = (proc_to_exe->pc + 1) % MEM_SIZE;
		if (env->flags->v && env->flags->verbose->show_pc)
			ft_show_pc(op_code, pc, proc_to_exe, env);
	}
	else if (proc_to_exe->cycle < 1)
		proc_to_exe->pc = (proc_to_exe->pc + 1) % MEM_SIZE;
	if (proc_to_exe->cycle > 0)
		proc_to_exe->cycle -= 1;
}

void			init_cycle(t_env *env, t_process *proc)
{
	static int	cycles_tab[16] = {10, 5, 5, 10, 10, 6, 6, 6
								, 20, 25, 25, 800, 10, 50, 1000, 2};
	int			op_code;

	if (proc->cycle <= 0)
	{
		op_code = env->arena[proc->pc];
		if (op_code > 0 && op_code <= 16)
			proc->cycle = cycles_tab[op_code - 1];
		proc->op = op_code;
	}
}

void			verification(t_env *env, t_loop *loop_params)
{
	t_process	*tmp;
	t_process	*tmp_next;

	tmp = env->process;
	while (tmp)
	{
		tmp_next = tmp->next;
		if (tmp->live <= 0)
			kill_proc(loop_params->cycle_to_die, env, tmp, &(env->process));
		tmp = tmp_next;
	}
	if (loop_params->decreased >= MAX_CHECKS - 1
			|| env->current_live >= NBR_LIVE)
	{
		loop_params->cycle_to_die -= CYCLE_DELTA;
		if (env->flags->v && env->flags->verbose->show_cycles)
		{
			ft_putstr("Cycle to die is now ");
			ft_putnbr(loop_params->cycle_to_die);
			ft_putchar('\n');
		}
		loop_params->decreased = 0;
	}
	else
		loop_params->decreased += 1;
}

int				list_size(t_process *proc)
{
	int	i;

	i = 0;
	while (proc)
	{
		i++;
		proc = proc->next;
	}
	return (i);
}

t_loop			*init_loop_params(void)
{
	t_loop	*loop_params;

	if (!(loop_params = malloc(sizeof(t_loop))))
		exit(0);
	loop_params->current_cycle = 0;
	loop_params->total_cycle = 0;
	loop_params->decreased = 0;
	loop_params->cycle_to_die = CYCLE_TO_DIE;
	return (loop_params);
}
