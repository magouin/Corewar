/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:42:06 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/08 16:54:53 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_size(int binary, int label)
{
	if (binary == 1)
		return (1);
	else if (binary == 2 && label == 4)
		return (4);
	else if (binary == 2 && label == 2)
		return (2);
	else if (binary == 3)
		return (2);
	return (0);
}
