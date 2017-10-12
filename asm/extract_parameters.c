/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_parameters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 11:57:28 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/13 13:04:37 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_param_type(char *str)
{
	if (str[0] == 'r')
		return (T_REG);
	if (str[0] == '%')
		return (T_DIR);
	return (T_IND);
}

static int	find_param_size(int param_type, int op_code)
{
	if (param_type == T_REG)
		return (1);
	if (param_type == T_DIR)
	{
		if (op_code == 1 || op_code == 2 || op_code == 6 || op_code == 7
				|| op_code == 8 || op_code == 13)
			return (4);
	}
	return (2);
}

static char	*get_value(char *str)
{
	char	*value;

	if (*str == 'r' || *str == '%')
	{
		value = ft_strdup(str + 1);
		free(str);
		return (value);
	}
	return (str);
}

static void	add_parameter(t_operation *op, t_parameter *param)
{
	t_list	*new_param;

	if (op->parameters == NULL)
		op->parameters = ft_lstnew(param, sizeof(t_parameter));
	else
	{
		if (!(new_param = malloc(sizeof(t_list))))
			exit(0);
		new_param->content = param;
		ft_lstadd_end(op->parameters, new_param);
	}
}

void		extract_parameters(char *line, t_operation *op)
{
	char		**parts;
	int			i;
	t_parameter	*param;
	char		*trimmed;

	parts = ft_strsplit(line, ',');
	check_params_nb(parts, op);
	i = 0;
	while (parts[i])
	{
		if (!(param = malloc(sizeof(t_parameter))))
			exit(0);
		trimmed = ft_strtrim(parts[i]);
		free(parts[i]);
		param->param_type = get_param_type(trimmed);
		param->param_size = find_param_size(param->param_type, op->code);
		param->value = get_value(trimmed);
		check_value(param->param_type, param->value);
		add_parameter(op, param);
		i++;
	}
	free(parts);
}
