/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:41:08 by magouin           #+#    #+#             */
/*   Updated: 2016/05/18 18:44:09 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

const struct s_flags	FLAGS_DF_VALUES = {0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0}, {0, 0, 0, 0}};

int			ft_flags2(char **str, struct s_flags *flags, int *x)
{
	if (str[*x][1] == 'b')
		flags->b = 1;
	else if (str[*x][1] == 'g')
		flags->g = 1;
	else if (str[*x][1] == 'a')
		flags->a = 1;
	else
		return (0);
	return (1);
}

int			ft_flags3(char **str, struct s_flags *flags, int *x)
{
	if (str[*x][1] == 'd')
	{
		flags->d = 1;
		(*x)++;
		if (ft_isdigit(str[*x]))
			flags->dnbr = ft_atoi(str[*x]);
		else
			return (0);
	}
	else if (str[*x][1] == 's')
	{
		flags->s = 1;
		(*x)++;
		if (ft_isdigit(str[*x]))
			flags->snbr = ft_atoi(str[*x]);
		else
			return (0);
	}
	return (1);
}

int			ft_flags(char **str, struct s_flags *flags, int *x, int ac)
{
	static int	n = 0;

	if (*x + 1 < ac)
	{
		if (!(ft_flags3(str, flags, x)))
			return (0);
		else if (str[*x][1] == 'v')
		{
			flags->v = 1;
			(*x)++;
			if (ft_isdigit(str[*x]))
				flags->vnbr = ft_atoi(str[*x]);
			else
				return (0);
		}
		else if (str[*x][1] == 'n')
		{
			(flags->n)[n] = 1;
			n++;
			(*x)++;
			if (ft_isdigit(str[*x]))
				flags->nnbr[n] = ft_atoi(str[*x]);
			else
				return (0);
		}
	}
	return (1);
}

void		ft_init_flags2(char **str, int ac, int x)
{
	while (x < ac)
	{
		if (x + MAX_PLAYERS < ac)
			ft_putstr_fd(2, "Too many champions\n", NULL);
		else if (ft_strcmp(ft_strrchr(str[x], '.'), ".cor") != 0)
			ft_putstr_fd(2, "Invalide File\n", NULL);
		else
		{
			x++;
			continue ;
		}
		exit(EXIT_FAILURE);
	}
}

char		**ft_init_flags(char **str, struct s_flags **flags, int ac)
{
	int		y;
	int		x;
	char	**ptr;

	x = 1;
	*flags = malloc(sizeof(struct s_flags));
	**flags = FLAGS_DF_VALUES;
	while (x < ac && ft_strcmp(ft_strrchr(str[x], '.'), ".cor") != 0)
	{
		if (str[x][0] != '-')
			ft_putstr_fd(2, "Invalide File\n", NULL);
		else if (!ft_flags2(str, *flags, &x) && !(ft_flags(str, *flags, &x, ac)))
			ft_usage();
		else
		{
			x++;
			continue ;
		}
		exit(EXIT_FAILURE);
	}
	ptr = str + x;
	ft_init_flags2(str, ac, x);
	return (ptr);
}
