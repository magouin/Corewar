/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:05:44 by arobin            #+#    #+#             */
/*   Updated: 2016/06/15 15:08:35 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void			precision(int a)
{
	char	*str;
	char	*nbr;
	int		len;
	int		x;

	x = 0;
	if (!(str = malloc(sizeof(char) * 5)))
		exit(EXIT_FAILURE);
	nbr = ft_itoa_base(a, 16);
	len = ft_strlen(nbr) - 1;
	while (4 - ++len > 0)
	{
		str[x] = '0';
		x++;
	}
	len = -1;
	while (x < 4)
	{
		str[x] = nbr[++len];
		x++;
	}
	str[4] = '\0';
	ft_putstr(str);
	free(nbr);
	free(str);
}

void			ft_show_pc(int op_code, int b_pc, t_process *pro, t_env *env)
{
	int		diff;

	diff = ft_mod(pro->pc - b_pc);
	if (op_code <= 0 || op_code > 16 || (op_code == 9 && pro->carry == 1))
		return ;
	ft_putstr("ADV ");
	ft_putnbr(diff);
	ft_putstr(" (0x");
	precision(b_pc);
	ft_putstr(" -> 0x");
	precision(b_pc + diff);
	ft_putstr(")");
	while (diff)
	{
		ft_putstr(" ");
		print_hex(env->arena[b_pc]);
		b_pc = (b_pc + 1) % MEM_SIZE;
		diff--;
	}
	ft_putstr(" \n");
}

static const t_operation g_operation[] =
{
	{0x01, &ft_live},
	{0x02, &ft_ld},
	{0x03, &ft_st},
	{0x04, &ft_add},
	{0x05, &ft_sub},
	{0x06, &ft_and},
	{0x07, &ft_or},
	{0x08, &ft_xor},
	{0x09, &ft_zjmp},
	{0x0a, &ft_ldi},
	{0x0b, &ft_sti},
	{0x0c, &ft_fork},
	{0x0d, &ft_lld},
	{0x0e, &ft_lldi},
	{0x0f, &ft_lfork},
	{0x10, &ft_aff},
	{0, 0}
};

int				ft_exec_operations(t_env *env, t_process *proc_to_exe)
{
	size_t	i;

	i = 0;
	while (g_operation[i].key != 0)
	{
		if (g_operation[i].key == proc_to_exe->op)
		{
			g_operation[i].func(env, proc_to_exe);
			return (1);
		}
		++i;
	}
	return (0);
}

void			inside_loop2(t_loop *loop_params, t_env *env)
{
	loop_params->current_cycle += 1;
	loop_params->total_cycle += 1;
	if (env->flags->v && env->flags->verbose->show_cycles)
	{
		ft_putstr("It is now cycle ");
		ft_putnbr(loop_params->total_cycle);
		ft_putchar('\n');
	}
}

void			inside_loop(t_loop *loop_params, t_env *env)
{
	t_process	*curr_proc;

	inside_loop2(loop_params, env);
	curr_proc = env->process;
	while (curr_proc)
	{
		init_cycle(env, curr_proc);
		exe_proc(env, curr_proc);
		curr_proc = curr_proc->next;
	}
	if (loop_params->current_cycle >= loop_params->cycle_to_die)
	{
		verification(env, loop_params);
		loop_params->current_cycle = 0;
		env->current_live = 0;
		reset_live_proc(env);
	}
	if (env->flags->d && env->flags->dnbr == loop_params->total_cycle)
	{
		ft_print_mem(env->arena);
		exit(0);
	}
	if (env->flags->s && loop_params->total_cycle % env->flags->snbr == 0)
		ft_print_mem(env->arena);
}
