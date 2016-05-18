/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_virtuelle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:11:20 by magouin           #+#    #+#             */
/*   Updated: 2016/05/18 16:57:23 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_len_prog(int fd, int x, int *len_prog)
{
	unsigned char	str[5];

	read(fd, str, 4);
	read(fd, str, 4);
	str[4] = '\0';
	while (x < 4)
	{
		*len_prog = *len_prog * 256 + (unsigned char)str[x];
		x++;
	}
}

void	ft_player(t_player *player)
{
	player->name = malloc(PROG_NAME_LENGTH + 1);
	player->comment = malloc(COMMENT_LENGTH + 1);
	player->name[PROG_NAME_LENGTH] = '\0';
	player->comment[COMMENT_LENGTH] = '\0';
	player->prog = NULL;
}

int		ft_check_size(int fd, t_player *player, char *av)
{
	char			buff[43];
	unsigned char	*tmp;
	int				len_prog;
	int				red;
	int				x;

	ft_player(player);
	read(fd, player->name, PROG_NAME_LENGTH);
	buff[42] = '\0';
	len_prog = 0;
	ft_len_prog(fd, 0, &len_prog);
	x = 0;
	red = 0;
	read(fd, player->comment, COMMENT_LENGTH);
	while ((red = read(fd, buff, 42)))
	{
		x += red;
		tmp = (unsigned char *)ft_strjoin(buff, (char*)player->prog);
		free(player->prog);
	}
	if (x - 4 != len_prog)
	{
		ft_putstr_fd(2, "Error: File ", av,
	" has a code size that differ from what its header says\n", NULL);
		return (0);
	}
	return (1);
}

int		ft_check_magic(int fd, char *st)
{
	char	str;
	int		rez;
	int		x;

	x = 1;
	read(fd, &str, 1);
	rez = 0;
	rez = (unsigned char)str;
	while (rez < (int)COREWAR_EXEC_MAGIC)
	{
		read(fd, &str, 1);
		rez = rez * 256 + (unsigned char)str;
		x++;
	}
	if (rez == COREWAR_EXEC_MAGIC)
		return (1);
	ft_putstr_fd(2, "Error: File ", st," has an invalid header\n", NULL);
	return (0);
}

int		main(int ac, char **av)
{
	char			**str;
	struct s_flags	flags;
	int				x;
	t_player		player;
	int				fd;

	x = 0;
	str = ft_init_flags(av, &flags, ac);
	//ft_printf("flags->a = %d\nflags->d = %d\nflags->s = %d\nflags->v = %d\nflags->b = %d\nflags->g = %d\nflags->n = %d\n", flags.a, flags.d, flags.s, flags.v, flags.b, flags.g, flags.n);
	while (str[x])
	{
		if ((fd = open(str[x], O_RDONLY)) < 0)
		{
			ft_putstr_fd(2, "Can't read source file ", str[x], "\n",  NULL);
			return (0);
		}
		if (!(ft_check_magic(fd, str[x]) && ft_check_size(fd, &player, str[x])))
			return (0);
		x++;
	}
	return (0);
}
