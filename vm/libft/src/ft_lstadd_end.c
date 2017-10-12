/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:54:20 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/03 16:40:38 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_end(t_list *alst, t_list *new)
{
	t_list	*temp;

	if (alst == NULL)
		return (new);
	temp = alst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
	return (alst);
}
