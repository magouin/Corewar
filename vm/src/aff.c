/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:26:00 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/14 18:37:58 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	ft_aff(t_env *env, t_process *proc)
{
	int	op_size;
	int	rez;

	rez = ft_getnumber(env->arena, (proc->pc + 2) % MEM_SIZE, 1);
	op_size = calculate_size(env->arena[(proc->pc + 1) % MEM_SIZE], 1, 4);
	if (FIRST(env->arena[(proc->pc + 1) % MEM_SIZE]) != 1
			|| rez <= 0 || rez > REG_NUMBER)
	{
		proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
		return ;
	}
	proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
	if (env->flags->a)
	{
		ft_putstr("Aff: ");
		ft_putchar((char)proc->reg[rez - 1]);
		ft_putchar('\n');
	}
}
