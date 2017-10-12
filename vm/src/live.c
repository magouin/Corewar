/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:50:23 by magouin           #+#    #+#             */
/*   Updated: 2016/06/15 14:55:34 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

static void		verb_live(t_process *proc, int value)
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
	ft_putstr(" | live ");
	ft_putnbr(value);
	ft_putstr("\n");
	free(str);
}

static t_player	*find_the_liver(t_env *env, int number)
{
	t_player	*tmp;

	tmp = env->player;
	while (tmp)
	{
		if (tmp->nbr == number)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void			ft_live(t_env *env, t_process *proc)
{
	int			op_size;
	t_player	*champ;
	int			value;

	op_size = 4;
	value = ft_getnumber(env->arena, proc->pc + 1, 4);
	proc->live += 1;
	env->current_live += 1;
	proc->pc = ft_mod((proc->pc + op_size + 1) % MEM_SIZE);
	if (env->flags->v && env->flags->verbose->show_operations)
		verb_live(proc, value);
	champ = find_the_liver(env, value);
	if (champ != NULL)
	{
		if (env->flags->v && env->flags->verbose->show_lives)
		{
			ft_putstr("Player ");
			ft_putnbr(-1 * value);
			ft_putstr(" (");
			ft_putstr(champ->name);
			ft_putstr(") is said to be alive\n");
		}
		env->live = champ->nbr;
	}
}
