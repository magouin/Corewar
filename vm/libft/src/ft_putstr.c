/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:58:36 by magouin           #+#    #+#             */
/*   Updated: 2016/06/15 12:00:30 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr(char const *str)
{
	int	len;

	if (str == NULL)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
