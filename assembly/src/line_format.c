/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 15:23:18 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/13 13:05:24 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	is_comment_or_empty(char *line)
{
	while (*line)
	{
		if (ft_isspace(*line))
			line++;
		else if (*line == COMMENT_CHAR)
			return (1);
		else
			return (0);
	}
	return (1);
}

int	is_name(char *line)
{
	char	*name_cmd;

	while (*line && ft_isspace(*line))
		line++;
	if (ft_strlen(line) >= ft_strlen(NAME_CMD_STRING))
	{
		name_cmd = ft_strsub(line, 0, ft_strlen(NAME_CMD_STRING));
		if (ft_strcmp(NAME_CMD_STRING, name_cmd) == 0)
		{
			free(name_cmd);
			return (1);
		}
		free(name_cmd);
	}
	return (0);
}

int	is_p_comment(char *line)
{
	char	*comment_cmd;

	while (*line && ft_isspace(*line))
		line++;
	if (ft_strlen(line) >= ft_strlen(COMMENT_CMD_STRING))
	{
		comment_cmd = ft_strsub(line, 0, ft_strlen(COMMENT_CMD_STRING));
		if (ft_strcmp(COMMENT_CMD_STRING, comment_cmd) == 0)
		{
			free(comment_cmd);
			return (1);
		}
		free(comment_cmd);
	}
	return (0);
}
