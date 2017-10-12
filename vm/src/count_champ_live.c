/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_champ_live.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 19:16:43 by arobin            #+#    #+#             */
/*   Updated: 2016/06/14 19:34:16 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				count_champ(t_player *player)
{
	int			i;
	t_player	*tmp;

	i = 0;
	tmp = player;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int				count_live(t_process *f_proc)
{
	t_process	*tmp;
	int			count;

	tmp = f_proc;
	count = 0;
	while (tmp != NULL)
	{
		count += tmp->live;
		tmp = tmp->next;
	}
	return (count);
}

int				count_t_param(t_list *params)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = params;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
