/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:41:08 by magouin           #+#    #+#             */
/*   Updated: 2016/05/18 14:30:10 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int 		ft_flags2(char **str, struct s_flags *flags, int *x)
{
	if (str[*x][1] == 'b')
		flags->b = 1;
	else if (str[*x][1] == 'g')
		flags->g = 1;
	else if (str[*x][1] == 'a')
		flags->a = 1;
	else if (str[*x][1] == 'n')
		flags->n = 1;
	else
		return (0);
	return (1);
}

int			ft_flags(char **str, struct s_flags *flags, int *x)
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
	else if (str[*x][1] == 'v')
	{
		flags->v = 1;
		(*x)++;
		if (ft_isdigit(str[*x]))
			flags->vnbr = ft_atoi(str[*x]);
		else
			return (0);
	}
	else
	{
		if (ft_flags2(str, flags, x))
			return (1);
		return (0);
	}
	return (1);
}

char		**ft_init_flags(char **str, struct s_flags *flags, int ac)
{
	int		y;
	int		x;
	char	**ptr;

	x = 1;
	while (str[x] != NULL && ft_strcmp(ft_strrchr(str[x], '.'), ".cor") != 0)
	{
		if (str[x][0] != '-')
			ft_putstr_fd(2, "Invalide File\n", NULL);
		else if (!(ft_flags(str, flags, &x)))
			ft_putstr_fd(2, "Usage: ./corewar [-d N -s N -v N | -b | -n] [-a]",
" <champion1.cor> <...>", NULL);
		else
		{
			x++;
			continue ;
		}
		exit(EXIT_FAILURE);
	}
	ptr = str + x;
	while (x < ac)
	{
		if (x + 4 < ac)
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
	return (ptr);
}
