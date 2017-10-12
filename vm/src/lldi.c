/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:52:35 by arobin            #+#    #+#             */
/*   Updated: 2016/06/14 18:18:27 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

static void	verb_lldi2(t_list *param, t_process *proc)
{
	ft_putstr(" ");
	ft_putnbr(((t_param*)param->next->content)->real_value);
	ft_putstr(" r");
	ft_putnbr(((t_param*)param->next->next->content)->value);
	ft_putstr("\n       | -> load from ");
	ft_putnbr(((t_param*)param->content)->real_value);
	ft_putstr(" + ");
	ft_putnbr(((t_param*)param->next->content)->real_value);
	ft_putstr(" = ");
	ft_putnbr(((t_param*)param->content)->real_value +
			((t_param*)param->next->content)->real_value);
	ft_putstr(" (with pc and mod ");
	ft_putnbr(proc->pc + (((t_param*)param->content)->
		real_value + (t_param*)param->next->content)->real_value);
	ft_putstr(")\n");
}

static void	verb_lldi(t_list *param, t_process *proc)
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
	ft_putstr(" | lldi ");
	ft_putnbr(((t_param*)param->content)->real_value);
	verb_lldi2(param, proc);
	free(str);
}

void		ft_lldi(t_env *env, t_process *proc)
{
	t_list	*params;
	int		value;
	int		op_size;

	op_size = calculate_size(env->arena[proc->pc + 1], 3, 2);
	params = get_parameters(env, proc);
	if (count_t_param(params) != 3
			|| va(1, 1, 1, (t_param *)params->content) == -1
			|| va(1, 1, 0, (t_param *)params->next->content) == -1
			|| va(1, 0, 0, (t_param *)params->next->next->content) == -1)
	{
		proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
		ft_free(params);
		return ;
	}
	value = ft_getnumber(env->arena, proc->pc
				+ (((t_param *)params->content)->real_value
				+ ((t_param *)params->next->content)->real_value), 4);
	proc->reg[((t_param *)params->next->next->content)->value - 1] = value;
	if (env->flags->v && env->flags->verbose->show_operations)
		verb_lldi(params, proc);
	proc->pc = ft_mod((proc->pc + op_size + 2) % MEM_SIZE);
	proc->carry = (value == 0) ? 1 : 0;
	ft_free(params);
}
