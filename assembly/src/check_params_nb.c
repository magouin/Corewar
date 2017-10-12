/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 19:09:55 by jnaddef           #+#    #+#             */
/*   Updated: 2016/05/17 13:48:12 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_params_nb(char **params, t_operation *op)
{
	int	params_nb;
	int	i;

	params_nb = 0;
	while (params[params_nb])
		params_nb++;
	i = 0;
	while (g_op_tab[i].cmd)
	{
		if (g_op_tab[i].op_code == op->code
				&& g_op_tab[i].arg_nbr != params_nb)
			throw_error(1);
		i++;
	}
}
