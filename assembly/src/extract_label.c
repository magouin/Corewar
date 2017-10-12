/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 11:54:10 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/12 17:26:45 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*get_label_value(char **line, char *label, char *tmp)
{
	int	label_size;
	int	i;

	label_size = ft_strlen(label);
	*line = ft_strsub(*line, label_size, ft_strlen(*line) - label_size);
	free(tmp);
	i = 0;
	while (i < label_size - 1)
	{
		if (ft_strchr(LABEL_CHARS, label[i]) == NULL)
			throw_error(1);
		i++;
	}
	return (label);
}

char		*extract_label(char **line)
{
	char	**parts;
	int		i;
	char	*tmp;
	char	*label;

	tmp = *line;
	parts = ft_split_whitespaces(tmp);
	label = ft_strdup(parts[0]);
	i = 0;
	while (parts[i])
		free(parts[i++]);
	free(parts);
	if (label != NULL && label_format(label))
	{
		return (get_label_value(line, label, tmp));
	}
	free(label);
	return (NULL);
}
