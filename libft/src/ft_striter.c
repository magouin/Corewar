/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:22:45 by magouin           #+#    #+#             */
/*   Updated: 2015/11/28 12:53:40 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	int n;

	n = 0;
	if (!s || !f)
		return ;
	while (s[n] != '\0')
	{
		f(s + n);
		n++;
	}
}