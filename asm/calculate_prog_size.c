/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_prog_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 19:34:12 by jnaddef           #+#    #+#             */
/*   Updated: 2016/05/18 16:26:14 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	calculate_prog_size(void)
{
	t_list	*temp;
	int		total_size;

	total_size = 0;
	temp = g_operations;
	while (temp)
	{
		total_size += ((t_operation *)temp->content)->op_length;
		temp = temp->next;
	}
	return (total_size);
}
