/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:46:48 by magouin           #+#    #+#             */
/*   Updated: 2016/06/14 18:08:41 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

static void		verb_sub(t_env *env, t_process *proc)
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
	ft_putstr(" | sub r");
	ft_putnbr(ft_getnumber(env->arena, proc->pc + 2, 1));
	ft_putstr(" r");
	ft_putnbr(ft_getnumber(env->arena, proc->pc + 3, 1));
	ft_putstr(" r");
	ft_putnbr(ft_getnumber(env->arena, proc->pc + 4, 1));
	ft_putchar('\n');
	free(str);
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
			|| param[1]->type != REG_CODE
			|| param[2]->type != REG_CODE
			|| (param[0]->type == REG_CODE
				&& (param[0]->value <= 0 || param[0]->value > REG_NUMBER))
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

void			ft_sub(t_env *env, t_process *proc)
{
	t_list	*params;
	t_param	**param;
	int		op_size;

	params = get_parameters(env, proc);
	op_size = calculate_size(env->arena[(proc->pc + 1) % MEM_SIZE], 3, 4);
	if (!(param = check_params(params)))
	{
		proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
		ft_free(params);
		return ;
	}
	proc->carry = 0;
	proc->reg[param[2]->value - 1] = param[0]->real_value
		- param[1]->real_value;
	if (env->flags->v && env->flags->verbose->show_operations)
		verb_sub(env, proc);
	proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
	if (proc->reg[param[2]->value - 1] == 0)
		proc->carry = 1;
	ft_free(params);
	free(param);
}
