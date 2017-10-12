/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_coding_byte.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:41:33 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/13 13:15:21 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_code(int param_type)
{
	if (param_type == T_REG)
		return (REG_CODE);
	if (param_type == T_DIR)
		return (DIR_CODE);
	return (IND_CODE);
}

static void	check_coding_byte(int op_code, int cb)
{
	if ((op_code == 2 || op_code == 13) && (cb == 144 || cb == 208))
		return ;
	if (op_code == 3 && (cb == 80 || cb == 112))
		return ;
	if ((op_code == 4 || op_code == 5) && cb == 84)
		return ;
	if ((op_code == 6 || op_code == 7 || op_code == 8)
			&& (cb == 84 || cb == 100 || cb == 116
			|| cb == 148 || cb == 164 || cb == 180
			|| cb == 212 || cb == 228 || cb == 244))
		return ;
	if ((op_code == 10 || op_code == 14)
			&& (cb == 84 || cb == 100 || cb == 148
			|| cb == 164 || cb == 212 || cb == 228))
		return ;
	if (op_code == 11 && (cb == 84 || cb == 88
				|| cb == 100 || cb == 104 || cb == 116 || cb == 120))
		return ;
	if (op_code == 16 && cb == 64)
		return ;
	if ((op_code == 1 || op_code == 9 || op_code == 12 || op_code == 15)
			&& cb == 128)
		return ;
	throw_error(1);
}

static int	calculate_coding_byte(t_operation *op)
{
	int			coding_byte;
	t_list		*temp;
	t_parameter	*param;
	int			pos;

	coding_byte = 0;
	temp = op->parameters;
	pos = 3;
	while (temp)
	{
		param = (t_parameter *)temp->content;
		coding_byte += get_code(param->param_type) * ft_pow(4, pos);
		pos--;
		temp = temp->next;
	}
	check_coding_byte(op->code, coding_byte);
	return (coding_byte);
}

int			has_coding_byte(t_operation *op)
{
	int	op_code;

	op_code = op->code;
	op->coding_byte = calculate_coding_byte(op);
	if (op_code == 1 || op_code == 9 || op_code == 12 || op_code == 15)
	{
		op->coding_byte = 0;
		return (0);
	}
	return (1);
}
