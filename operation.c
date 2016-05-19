/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:11:43 by magouin           #+#    #+#             */
/*   Updated: 2016/05/18 22:34:40 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

size_t	ft_getnumber(unsigned char *str, int ptr, int size)
{
	size_t	rez;
	int		x;

	x = 0;
	rez = 0;
	while (x < size)
	{
		rez = rez * 256 + str[(ptr + x + 1) % MEM_SIZE];
		x++;
	}
	return (rez);
}

void	ft_sti(unsigned char *str, int ptr, t_process *process)
{
	unsigned char	m;
	int				x;
	int				rez;
	int				size[3];

	x = 0;
	m = 0b11000000;
	while (x < 3)
	{
		if ((str[(ptr + 1) % MEM_SIZE] & m) >> (6 - 2 * x) == 3)
			size[x] = IND_SIZE;
		else if ((str[(ptr + 1) % MEM_SIZE] & m) >> (6 - 2 * x) == 2)
			size[x] = DIR_SIZE;
		else if ((str[(ptr + 1) % MEM_SIZE] & m) >> (6 - 2 * x) == 1)
			size[x] = REG_SIZE;
		m = m >> 2;
		x++;
	}
	rez = ft_getnumber(str, (ptr + 2) % MEM_SIZE, size[0]);
	str[(ptr + (ft_getnumber(str, (ptr + 3) % MEM_SIZE, size[1]) +
ft_getnumber(str, (ptr + 4) % MEM_SIZE, size[2])) % IDX_MOD) % MEM_SIZE] = rez;
	process->pc = (process->pc + ft_getnumber(str,
(ptr + 2) % MEM_SIZE, size[0]) + ft_getnumber(str, (ptr + 3) % MEM_SIZE,
size[1]) + ft_getnumber(str, (ptr + 4) % MEM_SIZE, size[2]) + 2) % MEM_SIZE;
}

void	ft_fork(unsigned char *str, int ptr, t_process **proc, t_process *par)
{
	t_process	*new;
	int			x;

	x = 0;
	new = malloc(sizeof(t_process));
	new->next = *proc;
	new->cycle = 0;
	new->carry = par->carry;
	new->pc = (par->pc +
		(ft_getnumber(str, ptr, IND_SIZE) % IDX_MOD)) % MEM_SIZE;
	new->reg = malloc(sizeof(void*) * REG_NUMBER);
	while (x < REG_NUMBER)
	{
		new->reg[x] = malloc(REG_SIZE);
		new->reg[x] = par->reg[x];
		x++;
	}
	par->pc = (par->pc + IND_SIZE + 1) % MEM_SIZE;
	*proc = new;
}
