/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:50:14 by arobin            #+#    #+#             */
/*   Updated: 2016/06/14 17:46:20 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

static void		verb_st(t_process *proc, t_param **p)
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
	ft_putstr(" | st r");
	ft_putnbr(p[0]->value);
	ft_putstr(" ");
	ft_putnbr(p[1]->value);
	ft_putchar('\n');
	free(str);
}

static t_param	**check_params(t_list *params)
{
	t_param	**param;

	if (!params || !params->next)
		return (NULL);
	if (!(param = malloc(sizeof(t_param) * 2)))
		exit(0);
	param[0] = (t_param *)params->content;
	param[1] = (t_param *)params->next->content;
	if (param[0]->type != REG_CODE || param[1]->type == DIR_CODE
			|| param[0]->value <= 0 || param[0]->value > REG_NUMBER
			|| (param[1]->type == REG_CODE
				&& (param[1]->value <= 0 || param[1]->value > REG_NUMBER)))
	{
		free(param);
		return (NULL);
	}
	return (param);
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

void			ft_st(t_env *env, t_process *proc)
{
	t_list	*params;
	t_param	**param;
	int		op_size;

	params = get_parameters(env, proc);
	op_size = calculate_size(env->arena[(proc->pc + 1) % MEM_SIZE], 2, 4);
	if (!(param = check_params(params)))
	{
		proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
		ft_free(params);
		return ;
	}
	if (param[1]->type == IND_CODE)
	{
		set_value(env, proc, param[1]->value, param[0]->real_value);
	}
	else
		proc->reg[param[1]->value - 1] = proc->reg[param[0]->value - 1];
	if (env->flags->v && env->flags->verbose->show_operations)
		verb_st(proc, param);
	proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
	ft_free(params);
	free(param);
}
