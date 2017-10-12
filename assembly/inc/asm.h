/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:40:27 by jnaddef           #+#    #+#             */
/*   Updated: 2017/10/12 18:25:14 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../libft/inc/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*g_name;
char	*g_p_comment;
t_list	*g_operations;
int		g_line_nb;

typedef struct	s_parameter
{
	int		param_type;
	int		param_size;
	char	*value;
}				t_parameter;

typedef struct	s_operation
{
	t_list	*labels;
	int		code;
	t_list	*parameters;
	int		op_length;
	int		coding_byte;
}				t_operation;

int				main(int argc, char **argv);
void			parse(char *file_name);
void			parse_name(char *line);
void			parse_p_comment(char *line);
void			parse_operation(char *line);
void			check_params_nb(char **params, t_operation *op);
void			throw_error(int err_code);
char			*extract_label(char **line);
int				extract_opcode(char **line);
void			extract_parameters(char *line, t_operation *op);
int				is_p_comment(char *line);
int				is_name(char *line);
int				is_comment_or_empty(char *line);
t_operation		*get_curr_operation(void);
void			fill_bytes(int fd);
void			fill_header(int fd);
int				create_output(char *input_name);
int				calculate_prog_size(void);
int				has_coding_byte(t_operation *op);
int				label_format(char *str);
int				label_format_ref(char *str);
void			fill_operations(int fd);
void			fill_parameter(t_operation *op, t_parameter *param, int fd);
void			check_valid(void);
int				contains_label(t_list *labels, char *label);
void			check_value(int type, char *value);
#endif
