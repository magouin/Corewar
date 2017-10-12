/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:38:01 by jnaddef           #+#    #+#             */
/*   Updated: 2016/05/18 12:42:49 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	label_format(char *word)
{
	if (word[ft_strlen(word) - 1] == ':')
		return (1);
	return (0);
}

int	label_format_ref(char *word)
{
	if (word[0] == ':')
		return (1);
	return (0);
}
