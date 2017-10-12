/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:17:14 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/14 21:57:06 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_value(int type, char *value)
{
	if (type == T_DIR && label_format_ref(value))
		return ;
	else if (!ft_isnumber(value))
		throw_error(1);
}
