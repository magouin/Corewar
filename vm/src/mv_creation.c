/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_creation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 14:21:25 by arobin            #+#    #+#             */
/*   Updated: 2016/06/14 19:42:46 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void				mv_creation(t_env *env)
{
	if ((env->arena = (unsigned char *)malloc(sizeof(unsigned char) *
		MEM_SIZE)) == NULL)
		exit(EXIT_FAILURE);
	ft_bzero(env->arena, MEM_SIZE);
}

void				write_champ(t_env *env, int pc, t_player *champ)
{
	int				i;

	i = 0;
	while (i < champ->len_prog)
	{
		env->arena[(pc + i) % MEM_SIZE] = champ->prog[i];
		i++;
	}
}

void				arena(t_player *c, struct s_flags *flags)
{
	t_env			*env;
	t_player		*current_champ;
	int				i;

	env = malloc(sizeof(t_env));
	env->player = c;
	env->flags = flags;
	env->num_last_process = 0;
	i = 1;
	current_champ = env->player;
	mv_creation(env);
	write_champ(env, 0, current_champ);
	if (current_champ->next != NULL)
	{
		current_champ = current_champ->next;
		while (current_champ->next != NULL)
		{
			write_champ(env, (MEM_SIZE / count_champ(c)) * i, current_champ);
			current_champ = current_champ->next;
			i++;
		}
		write_champ(env, (MEM_SIZE / count_champ(c)) * i, current_champ);
	}
	(flags->g) ? graphical_loop(env) : loop(env);
}
