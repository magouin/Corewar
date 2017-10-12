/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:19:46 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/13 13:08:15 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	find_endofstring(char *line)
{
	int	i;
	int	index;

	i = 0;
	while (line[i] && line[i] != '\"')
		i++;
	if (!line[i])
		throw_error(1);
	index = i;
	++i;
	while (line[i] && line[i] != COMMENT_CHAR)
	{
		if (!ft_isspace(line[i]))
			throw_error(1);
		i++;
	}
	return (index);
}

void		parse_p_comment(char *my_line)
{
	char	*tmp;
	int		i;
	char	*line;

	line = ft_strdup(my_line);
	tmp = line;
	i = 0;
	if (g_p_comment != NULL)
		throw_error(2);
	while (tmp[i] && ft_isspace(tmp[i]))
		i++;
	line = ft_strsub(tmp + i, ft_strlen(COMMENT_CMD_STRING)
			, ft_strlen(tmp + i) - ft_strlen(COMMENT_CMD_STRING));
	free(tmp);
	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != '\"')
		throw_error(1);
	i++;
	g_p_comment = ft_strsub(line + i, 0, find_endofstring(line + i));
	free(line);
	if (ft_strlen(g_p_comment) > COMMENT_LENGTH)
		throw_error(3);
}

void		parse_name(char *my_line)
{
	int		i;
	char	*tmp;
	char	*line;

	line = ft_strdup(my_line);
	tmp = line;
	i = 0;
	if (g_name != NULL)
		throw_error(2);
	while (tmp[i] && ft_isspace(tmp[i]))
		i++;
	line = ft_strsub(tmp + i, ft_strlen(NAME_CMD_STRING)
			, ft_strlen(tmp + i) - ft_strlen(NAME_CMD_STRING));
	free(tmp);
	tmp = line;
	i = 0;
	while (tmp[i] && ft_isspace(tmp[i]))
		i++;
	if (tmp[i] != '\"')
		throw_error(1);
	i++;
	g_name = ft_strsub(tmp + i, 0, find_endofstring(tmp + i));
	free(tmp);
	if (ft_strlen(g_name) > PROG_NAME_LENGTH)
		throw_error(3);
}
