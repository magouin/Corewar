/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 16:59:10 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/11 20:32:15 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		create_output(char *input_name)
{
	char	*output_name;
	int		fd;
	int		last_dot;
	int		i;

	i = 0;
	last_dot = ft_strlen(input_name);
	while (input_name[i])
	{
		if (input_name[i] == '.')
			last_dot = i;
		i++;
	}
	input_name[last_dot] = '\0';
	output_name = ft_strjoin(input_name, ".cor");
	fd = open(output_name, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	free(output_name);
	return (fd);
}
