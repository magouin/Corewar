/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 20:01:14 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/12 20:07:20 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	fill_op(t_operation *op, int fd)
{
	unsigned char	op_code;
	unsigned char	coding_byte;
	t_list			*temp;

	op_code = (unsigned char)op->code;
	if (op_code)
		write(fd, &op_code, 1);
	coding_byte = (unsigned char)op->coding_byte;
	if (coding_byte)
		write(fd, &coding_byte, 1);
	temp = op->parameters;
	while (temp)
	{
		fill_parameter(op, temp->content, fd);
		temp = temp->next;
	}
}

void		fill_operations(int fd)
{
	t_list		*temp;
	t_operation	*op;

	temp = g_operations;
	while (temp)
	{
		op = (t_operation *)temp->content;
		fill_op(op, fd);
		temp = temp->next;
	}
}
