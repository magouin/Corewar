/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_coding_byte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 20:43:37 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/14 22:05:59 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		no_coding_byte(int op_code)
{
	if (op_code == 1 || op_code == 9 || op_code == 12 || op_code == 15)
		return (1);
	return (0);
}
