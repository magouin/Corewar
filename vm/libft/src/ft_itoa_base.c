/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:05:03 by magouin           #+#    #+#             */
/*   Updated: 2016/06/14 01:09:56 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_calc_base(int n, int *len, int base)
{
	int k;

	k = n;
	if (n < 0)
	{
		len[1] = 1;
		n *= -1;
	}
	while (k)
	{
		k /= base;
		len[0]++;
	}
	return (n);
}

void	fln_base(char *str, int *len)
{
	if (len[1])
		str[0] = '-';
	str[len[0] + len[1]] = '\0';
}

char	*jedoismlloc_base(int n, int base)
{
	char	*st;
	char	*str;

	st = NULL;
	str = NULL;
	if (n == 0)
	{
		str = malloc(2);
		str[1] = '\0';
		str[0] = '0';
	}
	else if (n == -2147483648)
	{
		st = ft_itoa_base_long((long)(n * -1), base);
		str = ft_strjoin("-", st);
		free(st);
	}
	return (str);
}

char	*ft_itoa_base(int n, int base)
{
	int		len[2];
	char	*str;

	len[0] = 0;
	len[1] = 0;
	if (n == 0 || n == -2147483648)
	{
		str = jedoismlloc_base(n, base);
		return (str);
	}
	n = ft_calc_base(n, len, base);
	if (!(str = malloc(len[0] * sizeof(char) + 1 + len[1])))
		return (NULL);
	fln_base(str, len);
	while (n)
	{
		if (n % base < 10)
			str[len[0] - 1 + len[1]] = n % base + '0';
		else
			str[len[0] - 1 + len[1]] = n % base + 'a' - 10;
		n /= base;
		len[0]--;
	}
	return (str);
}
