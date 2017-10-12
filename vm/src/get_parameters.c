/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 18:48:41 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/15 14:02:49 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

static int		get_nb_bytes(int type, int op_code)
{
	if (type == REG_CODE)
		return (1);
	if (type == DIR_CODE)
	{
		if (op_code == 1 || op_code == 2 || op_code == 6 || op_code == 7
				|| op_code == 8 || op_code == 13)
			return (4);
	}
	return (2);
}

static int		get_real_value(t_env *env, t_process *proc, t_param *param)
{
	int real_value;

	real_value = 0;
	if (param->type == DIR_CODE)
		real_value = param->value;
	else if (param->type == REG_CODE)
	{
		if (param->value > 0 && param->value <= REG_NUMBER)
			real_value = proc->reg[param->value - 1];
	}
	if (param->type == IND_CODE)
	{
		real_value = ft_getnumber(env->arena
				, proc->pc + param->value % IDX_MOD, 4);
	}
	return (real_value);
}

static t_list	*init_param(int type, int *pc, t_env *env, t_process *proc)
{
	int		nb_bytes;
	t_list	*new_param;
	t_param *param;

	if (!(param = malloc(sizeof(t_param))))
		exit(0);
	if (!(new_param = malloc(sizeof(t_list))))
		exit(0);
	nb_bytes = get_nb_bytes(type, proc->op);
	param->type = type;
	param->bytes_nb = nb_bytes;
	param->value = ft_getnumber(env->arena, proc->pc + *pc, nb_bytes);
	if (nb_bytes == 2)
	{
		param->value = (short)param->value;
	}
	param->real_value = get_real_value(env, proc, param);
	new_param->content = param;
	new_param->next = NULL;
	*pc += nb_bytes;
	return (new_param);
}

static t_list	*get_param_dir(t_env *env, t_process *proc)
{
	int		nb_bytes;
	t_param	*param;
	t_list	*new_param;

	if (!(param = malloc(sizeof(t_param))))
		exit(0);
	if (!(new_param = malloc(sizeof(t_list))))
		exit(0);
	nb_bytes = get_nb_bytes(T_DIR, proc->op);
	param->type = T_DIR;
	param->value = ft_getnumber(env->arena, proc->pc + 1, nb_bytes);
	param->bytes_nb = nb_bytes;
	param->real_value = get_real_value(env, proc, param);
	new_param->content = param;
	new_param->next = NULL;
	return (new_param);
}

t_list			*get_parameters(t_env *env, t_process *proc)
{
	t_list		*params;
	int			first;
	int			second;
	int			third;
	int			pc;

	if (no_coding_byte(proc->op))
		return (get_param_dir(env, proc));
	first = FIRST(env->arena[ft_mod((proc->pc + 1) % MEM_SIZE)]);
	second = TWO(env->arena[ft_mod((proc->pc + 1) % MEM_SIZE)]);
	third = LAST(env->arena[ft_mod((proc->pc + 1) % MEM_SIZE)]);
	pc = 2;
	params = NULL;
	if (first != 0)
	{
		params = ft_lstadd_end(params, init_param(first, &pc, env, proc));
		if (second != 0)
		{
			params = ft_lstadd_end(params, init_param(second, &pc, env, proc));
			if (third != 0)
				params = ft_lstadd_end(params
						, init_param(third, &pc, env, proc));
		}
	}
	return (params);
}
