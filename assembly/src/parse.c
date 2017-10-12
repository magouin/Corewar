/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 13:29:11 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/13 19:56:17 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse(char *filename)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	g_line_nb = 0;
	g_name = NULL;
	g_p_comment = NULL;
	g_operations = NULL;
	while (get_next_line(fd, &line))
	{
		g_line_nb++;
		if (!is_comment_or_empty(line))
		{
			if (is_name(line))
				parse_name(line);
			else if (is_p_comment(line))
				parse_p_comment(line);
			else
				parse_operation(line);
		}
		free(line);
	}
	close(fd);
}
