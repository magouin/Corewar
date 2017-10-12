/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 17:14:49 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/12 20:09:39 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

const t_operation	g_default_op = {NULL, 0, NULL, 0, 0};

static t_operation	*create_new_operation(void)
{
	t_operation	*new_op;
	t_list		*new_link;

	if (!(new_op = malloc(sizeof(t_operation))))
		return (NULL);
	*new_op = g_default_op;
	if (g_operations == NULL)
		g_operations = ft_lstnew(new_op, sizeof(t_operation));
	else
	{
		if (!(new_link = malloc(sizeof(t_list))))
			return (NULL);
		new_link->content = new_op;
		ft_lstadd_end(g_operations, new_link);
	}
	return (new_op);
}

t_operation			*get_curr_operation(void)
{
	t_operation	*op;
	t_list		*temp;

	if (g_operations == NULL)
	{
		op = create_new_operation();
		return (op);
	}
	temp = g_operations;
	while (temp->next)
		temp = temp->next;
	if (((t_operation *)temp->content)->code != 0)
	{
		op = create_new_operation();
		return (op);
	}
	else
		return ((t_operation *)temp->content);
}
