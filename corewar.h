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
	int					len_prog;
	int					nbr;
	struct s_player		*next;
}						t_player;

typedef struct			s_process
{
	int					cycle;
	int					*reg;
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
	int					n[MAX_PLAYERS];
	int					nnbr[MAX_PLAYERS];
}						;

void					ft_sti(unsigned char *str, int ptr, t_process **process);
char					**ft_init_flags(char **s, struct s_flags **f, int a);
void					ft_usage(void);
void					arena(t_player *champ);
void					ft_fork(unsigned char *str, int ptr, t_process **proc, t_process *par);
void					ft_print_mem(unsigned char *str);

#endif
