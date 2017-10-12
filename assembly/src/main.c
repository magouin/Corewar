/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 13:04:29 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/12 16:12:23 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_labels(t_list *labels)
{
	t_list	*tmp;
	t_list	*tmp_next;
	char	*label;

	tmp = labels;
	while (tmp)
	{
		tmp_next = tmp->next;
		label = (char *)tmp->content;
		if (label != NULL)
			free(label);
		tmp->content = NULL;
		free(tmp);
		tmp = tmp_next;
	}
}

static void	free_params(t_list *params)
{
	t_list		*tmp;
	t_list		*tmp_next;
	t_parameter	*param;

	tmp = params;
	while (tmp)
	{
		tmp_next = tmp->next;
		param = (t_parameter *)tmp->content;
		free(param->value);
		param->value = NULL;
		free(param);
		param = NULL;
		free(tmp);
		tmp = tmp_next;
	}
}

static void	free_operations(void)
{
	t_list	*operation;
	t_list	*next_op;

	operation = g_operations;
	while (operation)
	{
		next_op = operation->next;
		free_labels(((t_operation *)operation->content)->labels);
		((t_operation *)operation->content)->labels = NULL;
		free_params(((t_operation *)operation->content)->parameters);
		((t_operation *)operation->content)->parameters = NULL;
		free(operation->content);
		operation->content = NULL;
		free(operation);
		operation = next_op;
	}
}

int			main(int argc, char **argv)
{
	int	output_fd;

	if (argc != 2)
	{
		ft_putstr("Usage: ./asm <sourcefile.s>\n");
		return (0);
	}
	parse(argv[1]);
	check_valid();
	output_fd = create_output(argv[1]);
	fill_bytes(output_fd);
	ft_putstr(GREEN);
	ft_putstr(".cor SUCCESSFULLY created!\n");
	ft_putstr(RESET);
	free(g_name);
	free(g_p_comment);
	free_operations();
	return (0);
}
