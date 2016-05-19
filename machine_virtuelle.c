/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_virtuelle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:11:20 by magouin           #+#    #+#             */
/*   Updated: 2016/05/18 18:34:11 by magouin          ###   ########.fr       */
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

void	ft_player(t_player *p, struct s_flags *flags)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->name = malloc(PROG_NAME_LENGTH + 1);
	player->comment = malloc(COMMENT_LENGTH + 1);
	player->name[PROG_NAME_LENGTH] = '\0';
	player->comment[COMMENT_LENGTH] = '\0';
	player->prog = NULL;
	player->next = p;
	if (flags->n)
		player->nbr = flags->nnbr;
}

int		ft_check_size(int fd, t_player *player, char *av, struct s_flags *flags)
{
	char			buff[43];
	unsigned char	*tmp;
	int				len_prog;
	int				red;
	int				x;

	ft_player(player, flags);
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
	if (red == 0)
	{
		ft_putstr_fd(2, "Error: File ", st, " is too small to be a champion\n", NULL);
		exit(EXIT_FAILURE);
	}
	if (red < 0)
	{
		ft_putstr_fd(2, "Error: Permission denied", NULL);
		exit(EXIT_FAILURE);
	}
	if (rez == COREWAR_EXEC_MAGIC)
		return (1);
	ft_putstr_fd(2, "Error: File ", st," has an invalid header\n", NULL);
	return (0);
}

void	ft_usage(void)
{
		ft_putstr_fd(1, "Usage: ./corewar [-d N -s N -v N | -b --stealth",
" | -n --stealth] [-a] <champion1.cor> <...>\n    -a        : Prints out",
"put from \"aff\" (Default is to hide it)\n#### TEXT OUTPUT MODE #######",
"###################################################\n    -d N      : Du",
"mps memory after N cycles then exits\n    -s N      : Runs N cycles, du",
"mps memory, pauses, then repeats\n    -v N      : Verbosity levels, can ",
"be added together to enable several\n                - 0 : Show only ess",
"entials\n                - 1 : Show lives\n                - 2 : Show cy",
"cles\n                - 4 : Show operations (Params are NOT litteral ...",
")\n                - 8 : Show deaths\n                - 16 : Show PC mov",
"ements (Except for jumps)\n#### BINARY OUTPUT MODE #####################",
"###################################\n    -b        : Binary output mode ",
"for corewar.42.fr\n    --stealth : Hides the real contents of the memory",
"\n#### NCURSES OUTPUT MODE #############################################",
"##########\n    -n        : Ncurses output mode\n    --stealth : Hides t",
"he real contents of the memory\n########################################",
"########################################\n", NULL);
		exit(EXIT_FAILURE);
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
	if (ac == 1)
		ft_usage();
	//ft_printf("flags->a = %d\nflags->d = %d\nflags->s = %d\nflags->v = %d\nflags->b = %d\nflags->g = %d\nflags->n = %d\n", flags.a, flags.d, flags.s, flags.v, flags.b, flags.g, flags.n);
	!(str[x]) ? ft_usage() : 0;
	while (str[x])
	{
		if ((fd = open(str[x], O_RDONLY)) < 0)
		{
			ft_putstr_fd(2, "Can't read source file ", str[x], "\n",  NULL);
			return (0);
		}
		if (!(ft_check_magic(fd, str[x]) && ft_check_size(fd, &player, str[x], &flags)))
			return (0);
		x++;
	}
	return (0);
}
