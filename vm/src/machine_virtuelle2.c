/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_virtuelle2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 20:06:31 by magouin           #+#    #+#             */
/*   Updated: 2016/06/15 13:10:37 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

const struct s_flags	g_flags_df = {0, 0, 0, 0, 0, 0, NULL, 0, 0, 0, 0};

void	ft_usage(void)
{
	ft_putstr_fd(1, "Usage: ./corewar [-d N -s N -v N -n N",
" | -g -a] <champion1.cor> <...>\n    -a        : Prints out",
"put from \"aff\" (Default is to hide it)\n#### TEXT OUTPUT MODE #######",
"###################################################\n    -d N      : Du",
"mps memory after N cycles then exits\n    -s N      : Runs N cycles, du",
"mps memory, pauses, then repeats\n    -v N      : Verbosity levels, can ",
"be added together to enable several\n                - 0 : Show only ess",
"entials\n                - 1 : Show lives\n                - 2 : Show cy",
"cles\n                - 4 : Show operations (Params are NOT litteral ...",
")\n                - 8 : Show deaths\n                - 16 : Show PC mov",
"ements (Except for jumps)\n",
"#### NCURSES OUTPUT MODE #############################################",
"##########\n    -g        : Ncurses output mode\n",
"########################################",
"########################################\n", NULL);
	exit(EXIT_FAILURE);
}

void	main4(t_player *player)
{
	t_player		*tmp_n;
	t_player		*tmp;

	tmp_n = player->next;
	tmp = player;
	while (tmp_n && tmp_n->next)
	{
		tmp_n = tmp_n->next;
		tmp = tmp->next;
	}
	if (tmp_n)
	{
		free(tmp_n->name);
		free(tmp_n->comment);
		free(tmp_n->prog);
		free(tmp_n);
	}
	tmp->next = NULL;
}

int		main3(char **av, t_player *player, struct s_flags *flags, int *x)
{
	ft_init_flags(av, flags, x);
	if (flags->n)
	{
		player->nbr_init = 1;
		player->nbr = flags->nnbr;
		flags->n = 0;
	}
	if (av[*x] == NULL)
	{
		main4(player);
		return (1);
	}
	return (0);
}

int		main2(char **av, t_player **player, struct s_flags *flags)
{
	int				x;
	int				fd;
	int				champ;

	x = 1;
	champ = 0;
	while (av[x])
	{
		*player = ft_player(*player);
		if (av[x][0] == '-')
			if (main3(av, *player, flags, &x))
				break ;
		if ((fd = open(av[x], O_RDONLY)) <= 0)
		{
			ft_putstr_fd(2, "Can't read source file ", av[x], "\n", NULL);
			exit(EXIT_FAILURE);
		}
		if (!(ft_magic(fd, av[x]) && ft_size(fd, *player, av[x], flags)))
			exit(EXIT_FAILURE);
		x++;
		champ++;
	}
	return (champ);
}

int		main(int ac, char **av)
{
	struct s_flags	*flags;
	t_player		*player;
	int				champ;

	player = NULL;
	flags = malloc(sizeof(struct s_flags));
	*flags = g_flags_df;
	(ac == 1) ? ft_usage() : 0;
	champ = main2(av, &player, flags);
	if (flags->g)
	{
		*flags = g_flags_df;
		flags->g = 1;
	}
	if (champ > MAX_PLAYERS)
	{
		ft_putstr_fd(2, "Too many champions\n", NULL);
		exit(EXIT_FAILURE);
	}
	(champ == 0) ? ft_usage() : 0;
	ft_player_nbr(player);
	arena(player, flags);
	return (0);
}
