/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 19:31:14 by arobin            #+#    #+#             */
/*   Updated: 2016/06/14 19:34:01 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

static int	ft_jump(int code, int label_jump)
{
	if (code == 0)
		return (0);
	if (code == 1)
		return (1);
	if (code == 3)
		return (2);
	return (label_jump);
}

int			calculate_size(int code, int param_max, int label)
{
	size_t offset;

	offset = 0;
	if (param_max >= 1)
		offset += ft_jump((code >> 6) & 0x3, label);
	if (param_max >= 2)
		offset += ft_jump((code >> 4) & 0x3, label);
	if (param_max >= 3)
		offset += ft_jump((code >> 2) & 0x3, label);
	return (offset);
}
