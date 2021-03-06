/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 19:24:19 by arobin            #+#    #+#             */
/*   Updated: 2016/06/14 18:22:33 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

static void		verb_lld(t_process *proc, t_param **p)
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
	ft_putstr(" | lld ");
	ft_putnbr(p[0]->real_value);
	ft_putstr(" r");
	ft_putnbr(p[1]->value);
	ft_putchar('\n');
	free(str);
}

static t_param	**check_params(t_list *params)
{
	t_param	**param;

	if (!params || !params->next)
		return (NULL);
	if (!(param = malloc(sizeof(t_param *) * 2)))
		exit(0);
	param[0] = (t_param *)params->content;
	param[1] = (t_param *)params->next->content;
	if (param[0]->type == REG_CODE || param[1]->type != REG_CODE
		|| (param[1]->type == REG_CODE
			&& (param[1]->value <= 0 || param[1]->value > REG_NUMBER)))
	{
		free(param);
		return (NULL);
	}
	return (param);
}

void			ft_lld(t_env *env, t_process *proc)
{
	t_list	*params;
	int		op_size;
	t_param	**param;

	params = get_parameters(env, proc);
	op_size = calculate_size(env->arena[(proc->pc + 1) % MEM_SIZE], 2, 4);
	if (!(param = check_params(params)))
	{
		proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
		ft_free(params);
		return ;
	}
	proc->reg[param[1]->value - 1] = param[0]->real_value;
	proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
	proc->carry = 0;
	if (env->flags->v && env->flags->verbose->show_operations)
		verb_lld(proc, param);
	if (proc->reg[param[1]->value - 1] == 0)
		proc->carry = 1;
	ft_free(params);
	free(param);
}
