/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 18:02:30 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/14 21:58:36 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnumber(char *str)
{
	int		i;
	int		is_number;

	is_number = 0;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		is_number = 1;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (is_number);
}
