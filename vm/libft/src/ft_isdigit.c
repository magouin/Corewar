/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:30:53 by magouin           #+#    #+#             */
/*   Updated: 2016/06/14 19:00:10 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isdigit(char *str)
{
	int x;

	x = 0;
	while (str[x])
	{
		if (str[x] >= 58 || str[x] <= 47)
			return (0);
		x++;
	}
	return (1);
}