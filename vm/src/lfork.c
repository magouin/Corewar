/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:33:10 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/14 18:37:18 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

static void	verb_lfork(t_env *env, t_process *par)
{
	char	*str;
	int		len;
	int		data;

	data = (short)ft_getnumber(env->arena, par->pc + 1, 2);
	str = ft_itoa(par->num);
	len = ft_strlen(str);
	ft_putchar('P');
	while (5 - len)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putnbr(par->num);
	ft_putstr(" | lfork ");
	ft_putnbr(data);
	ft_putstr(" (");
	ft_putnbr(par->pc + data);
	ft_putstr(")\n");
	free(str);
}

void		ft_lfork(t_env *env, t_process *par)
{
	t_process	*new;
	int			x;

	x = 0;
	if (!(new = malloc(sizeof(t_process))))
		exit(EXIT_FAILURE);
	new->next = env->process;
	new->cycle = 0;
	new->carry = par->carry;
	new->num = ++(env->num_last_process);
	new->live = par->live;
	new->pc = ft_mod((par->pc + (short)ft_getnumber(env->arena
					, par->pc + 1, IND_SIZE)) % MEM_SIZE);
	if (!(new->reg = malloc(sizeof(int) * REG_NUMBER)))
		exit(EXIT_FAILURE);
	while (x < REG_NUMBER)
	{
		new->reg[x] = par->reg[x];
		x++;
	}
	if (env->flags->v && env->flags->verbose->show_operations)
		verb_lfork(env, par);
	par->pc = ft_mod((par->pc + IND_SIZE + 1) % MEM_SIZE);
	env->process = new;
}
