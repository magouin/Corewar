/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 14:41:46 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/14 21:19:33 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	add_label(t_operation *operation, char *label)
{
	t_list	*new_label;

	if (operation->labels == NULL)
		operation->labels = ft_lstnew(label, sizeof(char *));
	else
	{
		if (!(new_label = malloc(sizeof(t_list))))
			exit(0);
		new_label->content = label;
		ft_lstadd_end(operation->labels, new_label);
	}
}

static char	*extract_not_comment(char *line)
{
	char	**parts;
	int		i;
	char	*not_comment;

	parts = ft_strsplit(line, COMMENT_CHAR);
	not_comment = ft_strdup(parts[0]);
	i = 0;
	while (parts[i])
		free(parts[i++]);
	free(line);
	free(parts);
	return (not_comment);
}

static int	add_params_size(t_operation *op)
{
	t_list	*params;
	int		total_size;

	total_size = 0;
	params = op->parameters;
	while (params)
	{
		total_size += ((t_parameter *)params->content)->param_size;
		params = params->next;
	}
	return (total_size);
}

static void	calculate_op_length(t_operation *op)
{
	int	total_length;

	total_length = 1;
	total_length += has_coding_byte(op);
	total_length += add_params_size(op);
	op->op_length = total_length;
}

void		parse_operation(char *my_line)
{
	t_operation	*curr_operation;
	char		*label;
	int			op_code;
	char		*line;

	if (g_name == NULL || g_p_comment == NULL)
		throw_error(4);
	line = ft_strdup(my_line);
	curr_operation = get_curr_operation();
	line = extract_not_comment(line);
	label = extract_label(&line);
	if (label != NULL)
		add_label(curr_operation, label);
	op_code = extract_opcode(&line);
	curr_operation->code = op_code;
	if (op_code != 0)
	{
		extract_parameters(line, curr_operation);
		calculate_op_length(curr_operation);
	}
	free(line);
}
