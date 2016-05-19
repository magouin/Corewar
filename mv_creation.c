/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_creation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 14:21:25 by arobin            #+#    #+#             */
/*   Updated: 2016/05/19 14:21:26 by arobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char		*mv_creation(void)
{
	unsigned char	*arena;

	if ((arena = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE + 1)) == NULL)
		return (NULL);
	ft_bzero(arena, MEM_SIZE);
	arena[MEM_SIZE + 1] = '\0';
	return (arena);
}

void				write_champ(unsigned char *start, t_player *champ)
{
	int				i;

	i = 0;
	while(i < 0x4d)
	{
		start[i] = champ->prog[i];
		i++;
	}
}

void				arena(t_player *champ)
{
	unsigned char	*arena;
	t_player		*current_champ;
	int				i;

	i = 1;
	ft_printf("c = %d\n", champ->prog[i]);
	current_champ = champ;
	arena = mv_creation();
	write_champ(arena, current_champ);
	if (current_champ->next != NULL)
	{
		current_champ = current_champ->next;
		while (current_champ->next != NULL)
		{
			write_champ(&arena[(MEM_SIZE / MAX_PLAYERS) * i], current_champ);
			current_champ = current_champ->next;
			i++;
		}
		write_champ(&arena[(MEM_SIZE / MAX_PLAYERS) * i], current_champ);
	}
	ft_print_mem(arena);
}