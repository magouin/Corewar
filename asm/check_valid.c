/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 21:15:21 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/12 16:13:14 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_label_exists(char *label)
{
	t_list	*temp;

	temp = g_operations;
	while (temp)
	{
		if (contains_label(((t_operation *)temp->content)->labels, label))
			return ;
		temp = temp->next;
	}
	throw_error(6);
}

static void	check_labels(void)
{
	t_list		*temp;
	t_list		*params;
	t_parameter *param;

	temp = g_operations;
	while (temp)
	{
		params = ((t_operation *)temp->content)->parameters;
		while (params)
		{
			param = (t_parameter *)params->content;
			if (label_format_ref(param->value))
				check_label_exists(param->value);
			params = params->next;
		}
		temp = temp->next;
	}
}

void		check_valid(void)
{
	if (g_operations == NULL)
		throw_error(5);
	check_labels();
}
