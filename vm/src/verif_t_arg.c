/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_t_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 07:00:24 by arobin            #+#    #+#             */
/*   Updated: 2016/06/11 21:03:56 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			va(int reg, int dir, int ind, t_param *param)
{
	if (reg == 0 && param->type == REG_CODE)
		return (-1);
	else if (dir == 0 && param->type == DIR_CODE)
		return (-1);
	else if (ind == 0 && param->type == IND_CODE)
		return (-1);
	else if (param->type == REG_CODE && (param->value <= 0 ||
		param->value > REG_NUMBER))
		return (-1);
	return (0);
}
