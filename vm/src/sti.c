/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:32:13 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/14 17:47:14 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

static void		verbose_sti2(t_param **param, t_process *proc)
{
	ft_putstr(" ");
	ft_putnbr(param[1]->real_value);
	ft_putstr(" ");
	ft_putnbr(param[2]->real_value);
	ft_putstr("\n       | -> store to ");
	ft_putnbr(param[1]->real_value);
	ft_putstr(" + ");
	ft_putnbr(param[2]->real_value);
	ft_putstr(" = ");
	ft_putnbr(param[1]->real_value + param[2]->real_value);
	ft_putstr(" (with pc and mod ");
	ft_putnbr(
		proc->pc + (param[1]->real_value + param[2]->real_value) % IDX_MOD);
	ft_putstr(")\n");
}

static void		verbose_sti(t_param **param, t_process *proc)
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
	ft_putstr(" | sti r");
	ft_putnbr(param[0]->value);
	verbose_sti2(param, proc);
	free(str);
}

static void		set_value(t_env *env, t_process *proc, int value
					, int real_value)
{
	env->arena[ft_mod(proc->pc + value % IDX_MOD)
		% MEM_SIZE] = real_value >> 24;
	env->arena[ft_mod(proc->pc + value % IDX_MOD + 1)
		% MEM_SIZE] = (real_value & 0xff0000) >> 16;
	env->arena[ft_mod(proc->pc + value % IDX_MOD + 2)
		% MEM_SIZE] = (real_value & 0xff00) >> 8;
	env->arena[ft_mod(proc->pc + value % IDX_MOD + 3)
		% MEM_SIZE] = real_value & 0xff;
}

static t_param	**check_params(t_list *params)
{
	t_param	**param;

	if (!params || !params->next || !params->next->next)
		return (NULL);
	if (!(param = malloc(sizeof(t_param *) * 3)))
		exit(0);
	param[0] = (t_param *)params->content;
	param[1] = (t_param *)params->next->content;
	param[2] = (t_param *)params->next->next->content;
	if (param[0]->type != REG_CODE
			|| param[2]->type == IND_CODE
			|| param[0]->value <= 0
			|| param[0]->value > REG_NUMBER
			|| (param[1]->type == REG_CODE
				&& (param[1]->value <= 0 || param[1]->value > REG_NUMBER))
			|| (param[2]->type == REG_CODE
				&& (param[2]->value <= 0 || param[2]->value > REG_NUMBER)))
	{
		free(param);
		return (NULL);
	}
	return (param);
}

void			ft_sti(t_env *env, t_process *proc)
{
	t_list	*params;
	int		op_size;
	t_param	**param;
	int		rez;

	params = get_parameters(env, proc);
	op_size = calculate_size(env->arena[(proc->pc + 1) % MEM_SIZE], 3, 2);
	if (!(param = check_params(params)))
	{
		proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
		ft_free(params);
		return ;
	}
	rez = param[1]->real_value + param[2]->real_value;
	set_value(env, proc, rez, param[0]->real_value);
	if (env->flags->v && env->flags->verbose->show_operations)
		verbose_sti(param, proc);
	proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
	ft_free(params);
	free(param);
}
