/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:40:34 by arobin            #+#    #+#             */
/*   Updated: 2016/06/14 18:03:50 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void		verb_zjmp(t_process *proc, int p)
{
	char	*str;
	int		len;

	str = ft_itoa(proc->num);
	len = ft_strlen(str);
	ft_putchar('P');
	while (5 - len)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putnbr(proc->num);
	ft_putstr(" | zjmp ");
	ft_putnbr(p);
	proc->carry ? ft_putstr(" OK\n") : ft_putstr(" FAILED\n");
	free(str);
}

void		ft_zjmp(t_env *env, t_process *proc)
{
	int		op_size;

	op_size = 2;
	if (env->flags->v && env->flags->verbose->show_operations)
		verb_zjmp(proc, ((short)ft_getnumber(env->arena, proc->pc + 1, 2)));
	if (proc->carry == 1)
		proc->pc = ft_mod((proc->pc + ((short)ft_getnumber(env->arena
							, proc->pc + 1, 2)) % IDX_MOD) % MEM_SIZE);
	else
		proc->pc = ft_mod((proc->pc + op_size + 1) % MEM_SIZE);
}
