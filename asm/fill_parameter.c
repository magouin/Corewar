/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_parameter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 13:14:24 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/13 13:07:25 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_nb_bytes(t_operation *op, t_parameter *param)
{
	if (param->param_type == T_REG)
		return (1);
	if (param->param_type == T_DIR)
	{
		if (op->code == 1 || op->code == 2 || op->code == 6 || op->code == 7
				|| op->code == 8 || op->code == 13)
			return (4);
	}
	return (2);
}

static int	dist_to_label(t_operation *op, char *label)
{
	int		dist;
	t_list	*temp;
	int		op_position;
	int		label_position;
	int		position;

	temp = g_operations;
	dist = 0;
	label_position = -1;
	op_position = -1;
	position = 0;
	while (temp && (label_position == -1 || op_position == -1))
	{
		if ((t_operation *)temp->content == op)
			op_position = position;
		if (label_position == -1
			&& ((t_operation *)temp->content)->labels != NULL
			&& contains_label(((t_operation *)temp->content)->labels, label))
			label_position = position;
		position += ((t_operation *)temp->content)->op_length;
		temp = temp->next;
	}
	dist = label_position - op_position;
	return (dist);
}

static int	get_value(t_operation *op, t_parameter *param)
{
	if (label_format_ref(param->value))
	{
		return (dist_to_label(op, param->value));
	}
	return (ft_atoi(param->value));
}

static void	write_parameter(int value, int nb_bytes, int fd)
{
	unsigned char	*c;
	int				i;

	if (!(c = malloc(sizeof(char) * nb_bytes)))
		exit(0);
	i = 0;
	while (i < nb_bytes)
	{
		c[i] = (value >> (8 * i)) & 0xFF;
		i++;
	}
	while (--i >= 0)
	{
		write(fd, &(c[i]), 1);
	}
	free(c);
}

void		fill_parameter(t_operation *op, t_parameter *param, int fd)
{
	int	int_value;
	int nb_bytes;

	if (param->param_type == T_REG)
		int_value = ft_atoi(param->value);
	else
		int_value = get_value(op, param);
	nb_bytes = get_nb_bytes(op, param);
	write_parameter(int_value, nb_bytes, fd);
}
