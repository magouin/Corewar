/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:41:08 by magouin           #+#    #+#             */
/*   Updated: 2016/06/14 19:33:12 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int					ft_flags2(char **str, struct s_flags *flags, int *x)
{
	if (str[*x][1] == 'b')
		flags->b = 1;
	else if (str[*x][1] == 'g')
		flags->g = 1;
	else if (str[*x][1] == 'a')
		flags->a = 1;
	else
		return (1);
	return (0);
}

int					ft_flags3(char **str, struct s_flags *flags, int *x)
{
	if (str[*x][1] == 'd')
	{
		flags->d = 1;
		(*x)++;
		if (str[*x] && ft_isdigit(str[*x]))
			flags->dnbr = ft_atoi(str[*x]);
		else
			ft_usage();
	}
	else if (str[*x][1] == 's')
	{
		flags->s = 1;
		(*x)++;
		if (str[*x] && ft_isdigit(str[*x]))
			flags->snbr = ft_atoi(str[*x]);
		else
			ft_usage();
	}
	else
		return (0);
	return (1);
}

struct s_verbose	*ft_verbose(int c)
{
	int					mask;
	struct s_verbose	*v;

	v = malloc(sizeof(struct s_verbose));
	mask = 16;
	if (mask / 16 & c)
		v->show_lives = 1;
	else
		v->show_lives = 0;
	v->show_cycles = ((mask / 8) & c) ? 1 : 0;
	if ((mask / 4) & c)
		v->show_operations = 1;
	else
		v->show_operations = 0;
	if ((mask / 2) & c)
		v->show_deaths = 1;
	else
		v->show_deaths = 0;
	if ((mask) & c)
		v->show_pc = 1;
	else
		v->show_pc = 0;
	return (v);
}

int					ft_flags(char **str, struct s_flags *flags, int *x)
{
	if (str[*x][1] == 'v')
	{
		flags->v = 1;
		(*x)++;
		if (str[*x] && ft_isdigit(str[*x]))
			flags->verbose = ft_verbose(ft_atoi(str[*x]));
		else
			ft_usage();
	}
	else if (str[*x][1] == 'n')
	{
		flags->n = 1;
		(*x)++;
		if (str[*x] && ft_isdigit(str[*x]))
			flags->nnbr = -1 * ft_atoi(str[*x]);
		else
			ft_usage();
	}
	else
	{
		if (!ft_flags3(str, flags, x))
			return (1);
	}
	return (0);
}

void				ft_init_flags(char **str, struct s_flags *flags, int *x)
{
	if (str[*x][2] != '\0')
		ft_usage();
	if (ft_flags2(str, flags, x) && ft_flags(str, flags, x))
	{
		ft_usage();
		exit(EXIT_FAILURE);
	}
	(*x)++;
	if (str[*x] && str[*x][0] == '-')
		ft_init_flags(str, flags, x);
}
