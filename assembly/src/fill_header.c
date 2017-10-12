/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 12:05:10 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/13 13:05:02 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	fill_magic(int fd)
{
	int				magic;
	unsigned char	c[4];

	magic = COREWAR_EXEC_MAGIC;
	c[0] = magic & 0xFF;
	c[1] = (magic >> 8) & 0xFF;
	c[2] = (magic >> 16) & 0xFF;
	c[3] = (magic >> 24) & 0xFF;
	write(fd, &(c[3]), 1);
	write(fd, &(c[2]), 1);
	write(fd, &(c[1]), 1);
	write(fd, &(c[0]), 1);
}

static void	fill_name(int fd)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (g_name[i])
	{
		c = (unsigned char)g_name[i];
		write(fd, &c, 1);
		i++;
	}
	c = 0;
	while (i < PROG_NAME_LENGTH + 4)
	{
		write(fd, &c, 1);
		i++;
	}
}

static void	fill_prog_size(int fd)
{
	int				prog_size;
	unsigned char	c[4];

	prog_size = calculate_prog_size();
	c[0] = prog_size & 0xFF;
	c[1] = (prog_size >> 8) & 0xFF;
	c[2] = (prog_size >> 16) & 0xFF;
	c[3] = (prog_size >> 24) & 0xFF;
	write(fd, &(c[3]), 1);
	write(fd, &(c[2]), 1);
	write(fd, &(c[1]), 1);
	write(fd, &(c[0]), 1);
}

static void	fill_comment(int fd)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (g_p_comment[i])
	{
		c = (unsigned char)g_p_comment[i];
		write(fd, &c, 1);
		i++;
	}
	c = 0;
	while (i < COMMENT_LENGTH + 4)
	{
		write(fd, &c, 1);
		i++;
	}
}

void		fill_header(int fd)
{
	fill_magic(fd);
	fill_name(fd);
	fill_prog_size(fd);
	fill_comment(fd);
}
