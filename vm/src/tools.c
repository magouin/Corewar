/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:41:59 by arobin            #+#    #+#             */
/*   Updated: 2016/06/02 15:47:53 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int			ft_get_arg(int encod, unsigned char *arena, int pc)
{
	int		ret;

	ret = 0;
	if (encod == 1)
		ret = (int)(arena[(pc + 1) % MEM_SIZE]);
	else if (encod == 2)
		ret = (int)(arena[(pc + 1) % MEM_SIZE] | arena[(pc + 2) % MEM_SIZE]);
	else if (encod == 4)
		ret = (int)(arena[(pc + 1) % MEM_SIZE] | arena[(pc + 2) % MEM_SIZE] |
arena[(pc + 3) % MEM_SIZE]);
	return (ret);
}
