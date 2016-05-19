/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:34:25 by magouin           #+#    #+#             */
/*   Updated: 2016/05/18 18:06:16 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "inc/op.h"
# include "libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct			s_player
{
	char				*name;
	char				*comment;
	unsigned char		*prog;
	int					nbr;
	struct s_player		*next;
}						t_player;

typedef struct			s_process
{
	int					cycle;
	void				**reg;
	int					carry;
	struct s_process	*next;
	int					pc;
	int					live;
}						t_process;

struct					s_flags
{
	int					a;
	int					d;
	int					dnbr;
	int					s;
	int					snbr;
	int					v;
	int					vnbr;
	int					b;
	int					g;
	int					n;
	int					nnbr;
}						;

char					**ft_init_flags(char **s, struct s_flags *f, int a);
void					ft_usage(void);

#endif
