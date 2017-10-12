/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_opcode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 11:56:38 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/12 20:06:56 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	count_spaces(char *str)
{
	int	cpt;

	cpt = 0;
	while (ft_isspace(str[cpt]))
		cpt++;
	return (cpt);
}

static int	get_code_value(char *op_name, char **line, char *tmp, int nb_spaces)
{
	int	i;
	int	code;

	i = 0;
	code = 0;
	while (g_op_tab[i].cmd)
	{
		if (ft_strcmp(g_op_tab[i].cmd, op_name) == 0)
			code = g_op_tab[i].op_code;
		i++;
	}
	if (code == 0 && !is_comment_or_empty(op_name))
		throw_error(1);
	*line = ft_strsub(tmp, ft_strlen(op_name) + nb_spaces
			, ft_strlen(tmp) - ft_strlen(op_name) - nb_spaces);
	free(tmp);
	free(op_name);
	return (code);
}

int			extract_opcode(char **line)
{
	char	**parts;
	int		i;
	int		nb_spaces;
	char	*op_name;
	char	*tmp;

	if (is_comment_or_empty(*line))
		return (0);
	tmp = *line;
	nb_spaces = count_spaces(*line);
	parts = ft_split_whitespaces(*line);
	op_name = ft_strdup(parts[0]);
	i = 0;
	while (parts[i])
		free(parts[i++]);
	free(parts);
	if (op_name != NULL)
	{
		return (get_code_value(op_name, line, tmp, nb_spaces));
	}
	else
		throw_error(1);
	return (0);
}
