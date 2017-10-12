/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:46:32 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/11 21:09:37 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	contains_label(t_list *labels, char *label)
{
	t_list	*temp;
	char	*label1;
	char	*label2;

	temp = labels;
	label1 = ft_strtrim_char(label, ':');
	while (temp)
	{
		label2 = ft_strtrim_char(temp->content, ':');
		if (ft_strcmp(label1, label2) == 0)
		{
			free(label1);
			free(label2);
			return (1);
		}
		free(label2);
		temp = temp->next;
	}
	free(label1);
	return (0);
}
