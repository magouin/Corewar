/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_virtuelle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:11:20 by magouin           #+#    #+#             */
/*   Updated: 2016/06/15 12:44:34 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void		ft_len_prog(int fd, int *x, t_player *p, int *red)
{
	unsigned char	str[5];

	p->len_prog = 0;
	read(fd, str, 4);
	read(fd, str, 4);
	str[4] = '\0';
	*x = 0;
	while (*x < 4)
	{
		p->len_prog = p->len_prog * 256 + (unsigned char)str[*x];
		(*x)++;
	}
	*x = 0;
	*red = 0;
}

void		ft_player_nbr(t_player *player)
{
	t_player	*tmp;
	t_player	*p;
	int			d;

	d = 0;
	p = player;
	while (p)
	{
		tmp = player;
		if (p->nbr_init == 0 && d-- < 1)
		{
			while (tmp)
			{
				if (tmp->nbr == d)
				{
					tmp = player;
					d--;
				}
				else
					tmp = tmp->next;
			}
			p->nbr = d;
		}
		p = p->next;
	}
}

t_player	*ft_player(t_player *p)
{
	t_player	*player;
	t_player	*tmp;

	tmp = p;
	player = malloc(sizeof(t_player));
	player->name = malloc(PROG_NAME_LENGTH + 1);
	player->comment = malloc(COMMENT_LENGTH + 1);
	player->name[PROG_NAME_LENGTH] = '\0';
	player->comment[COMMENT_LENGTH] = '\0';
	player->prog = NULL;
	player->nbr_init = 0;
	player->nbr = 0;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = player;
	else
		p = player;
	player->next = NULL;
	player->prev = p ? p : NULL;
	return (p);
}

int			ft_size(int fd, t_player *player, char *av, struct s_flags *flags)
{
	char			buff[43];
	int				red;
	int				x;

	flags = NULL;
	while (player->next)
		player = player->next;
	read(fd, player->name, PROG_NAME_LENGTH);
	buff[42] = '\0';
	ft_len_prog(fd, &x, player, &red);
	read(fd, player->comment, COMMENT_LENGTH);
	read(fd, buff, 4);
	player->prog = malloc(player->len_prog);
	red = read(fd, (char *)player->prog, player->len_prog);
	x = 0;
	red += read(fd, buff, 42);
	if (red != player->len_prog)
		ft_putstr_fd(2, "Error: File ", av,
" has a code size that differ from what its header says\n", NULL);
	else if (red > MEM_SIZE / 6)
		ft_putstr_fd(2, "Error: File ", av, " has too large a code (", ft_itoa(
red), " bytes > ", ft_itoa(MEM_SIZE / 6), " bytes)\n", NULL);
	else
		return (1);
	return (0);
}

int			ft_magic(int fd, char *st)
{
	char	str;
	int		rez;
	int		red;
	int		x;

	x = 1;
	rez = 0;
	red = 0;
	red = read(fd, &str, 1);
	rez = (unsigned char)str;
	while (red > 0 && rez < (int)COREWAR_EXEC_MAGIC)
	{
		red = read(fd, &str, 1);
		rez = rez * 256 + (unsigned char)str;
		x++;
	}
	if (rez == COREWAR_EXEC_MAGIC)
		return (1);
	if (red == 0)
		ft_putstr_fd(2, "Error: File ", st,
				" is too small to be a champion\n", NULL);
	else
		ft_putstr_fd(2, "Error: File ", st, " has an invalid header\n", NULL);
	exit(EXIT_FAILURE);
}
