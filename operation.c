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
		rez = rez * 256 + str[(ptr + x) % MEM_SIZE];
		x++;
	}
	return (rez);
}

void	ft_tmp_1(unsigned char *str, int ptr, int rez, int *size)
{
	int patern;
	int mask[4];

	mask[0] = 0xff000000;
	mask[1] = 0xff0000;
	mask[2] = 0xff00;
	mask[3] = 0xff;
	patern = ft_getnumber(str, ptr + 2 + size[0], size[1])
	+ ft_getnumber(str, ptr + 2 + size[0] + size[1], size[2]);
	str[ptr + patern] = (rez & mask[0]) >> 24;
	str[ptr + patern + 1] = (rez & mask[1]) >> 16;
	str[ptr + patern + 2] = (rez & mask[2]) >> 8;
	str[ptr + patern + 3] = (rez & mask[3]);
	ft_printf("ptr + patern + 3 = %d\n", ptr + patern + 3);
	ft_printf("0 = %d\n", (rez & mask[0]) >> 24);
	ft_printf("1 = %d\n", (rez & mask[1]) >> 16);
	ft_printf("2 = %d\n", (rez & mask[2]) >> 8);
	ft_printf("3 = %d\n", (rez & mask[3]));
}

void	ft_sti(unsigned char *str, int ptr, t_process **process)
{
	unsigned char	m;
	int				x;
	int				rez;
	int				size[3];
	int				tmp;

	x = 0;
	m = 192;
	tmp = (str[(ptr + 1) % MEM_SIZE] & m) >> (6 - 2 * x);
	while (x < 3)
	{
		if (((str[(ptr + 1) % MEM_SIZE] & m) >> (6 - 2 * x)) == 3)
			size[x] = T_IND;
		else if (((str[(ptr + 1) % MEM_SIZE] & m) >> (6 - 2 * x)) == 2)
			size[x] = T_DIR;
		else if (((str[(ptr + 1) % MEM_SIZE] & m) >> (6 - 2 * x)) == 1)
			size[x] = T_REG;
		else
			size[x] = 0;
		m = m >> 2;
		x++;
	}
	m = 12;
	x++;
	if (tmp != 1 || ((str[(ptr + 1) % MEM_SIZE] & m) >> (6 - 2 * x)) == 3)
	{
		(*process)->pc = ((*process)->pc + size[0] + size[1] + size[2] + 2) % MEM_SIZE;
		return ;
	}
	ft_tmp_1(str, ptr, (*process)->reg[(ft_getnumber(str, ptr + 2, size[0]) - 1) % REG_NUMBER], size); 
	(*process)->pc = ((*process)->pc + size[0] + size[1] + size[2] + 2) % MEM_SIZE;
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
		(ft_getnumber(str, ptr + 1, T_IND) % IDX_MOD)) % MEM_SIZE;
	new->reg = malloc(sizeof(int) * REG_NUMBER);
	while (x < REG_NUMBER)
	{
		new->reg[x] = par->reg[x];
		x++;
	}
	par->pc = (par->pc + T_IND + 1) % MEM_SIZE;
	*proc = new;
}
