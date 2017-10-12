/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:25:10 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/14 18:02:31 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

static void		verb_or(t_process *proc, t_param **p)
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
	ft_putstr(" | or ");
	ft_putnbr(p[0]->real_value);
	ft_putstr(" ");
	ft_putnbr(p[1]->real_value);
	ft_putstr(" r");
	ft_putnbr(p[2]->value);
	ft_putchar('\n');
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
	if (param[2]->type != REG_CODE
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

void			ft_or(t_env *env, t_process *proc)
{
	t_list	*param;
	t_param **par;
	int		op_size;

	param = get_parameters(env, proc);
	op_size = calculate_size(env->arena[(proc->pc + 1) % MEM_SIZE], 3, 4);
	if (!(par = check_params(param)))
	{
		proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
		ft_free(param);
		return ;
	}
	proc->carry = 0;
	proc->reg[par[2]->value - 1] = par[0]->real_value | par[1]->real_value;
	proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
	if (env->flags->v && env->flags->verbose->show_operations)
		verb_or(proc, par);
	if (proc->reg[par[2]->value - 1] == 0)
		proc->carry = 1;
	ft_free(param);
	free(par);
}
