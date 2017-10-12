/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:34:25 by magouin           #+#    #+#             */
/*   Updated: 2016/06/15 14:53:30 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <ncurses.h>

# define FIRST(x)	(((x) >> 6) & 0x3)
# define TWO(x)		(((x) >> 4) & 0x3)
# define LAST(x)	(((x) >> 2) & 0x3)

typedef struct			s_loop
{
	int					current_cycle;
	int					total_cycle;
	int					cycle_to_die;
	int					decreased;
}						t_loop;

typedef struct			s_player
{
	char				*name;
	char				*comment;
	unsigned char		*prog;
	int					len_prog;
	int					nbr_init;
	int					nbr;
	struct s_player		*next;
	struct s_player		*prev;
}						t_player;

typedef struct			s_process
{
	int					num;
	int					cycle;
	int					*reg;
	int					carry;
	int					op;
	struct s_process	*next;
	int					pc;
	int					live;
}						t_process;

typedef struct			s_param
{
	int					type;
	int					value;
	int					real_value;
	int					bytes_nb;
}						t_param;

typedef struct			s_verbose
{
	int					show_lives;
	int					show_cycles;
	int					show_operations;
	int					show_deaths;
	int					show_pc;
}						t_verbose;

struct					s_flags
{
	int					a;
	int					d;
	int					dnbr;
	int					s;
	int					snbr;
	int					v;
	struct s_verbose	*verbose;
	int					b;
	int					g;
	int					n;
	int					nnbr;
}						;

typedef struct			s_env
{
	t_player			*player;
	t_process			*process;
	struct s_flags		*flags;
	int					live;
	int					current_live;
	unsigned char		*arena;
	int					num_last_process;
}						t_env;

typedef struct			s_operation
{
	unsigned char		key;
	void				(*func)(t_env *, t_process *);
}						t_operation;

void					ft_aff(t_env *env, t_process *proc);
void					ft_zjmp(t_env *env, t_process *proc);
void					ft_st(t_env *env, t_process *proc);
void					ft_sti(t_env *env, t_process *process);
void					ft_fork(t_env *env, t_process *proc);
void					ft_add(t_env *env, t_process *pro);
void					ft_sub(t_env *env, t_process *pro);
void					ft_lfork(t_env *env, t_process *r);
void					ft_ld(t_env *env, t_process *proc);
void					ft_xor(t_env *env, t_process *proc);
void					ft_or(t_env *env, t_process *proc);
void					ft_lld(t_env *env, t_process *proc);
void					ft_ldi(t_env *env, t_process *proc);
void					ft_lldi(t_env *env, t_process *proc);
void					ft_live(t_env *env, t_process *proc);
void					ft_init_flags(char **s, struct s_flags *f, int *a);
void					ft_usage(void);
void					arena(t_player *champ, struct s_flags *flags);
void					verification(t_env *env, t_loop *loop);
t_player				*ft_player(t_player *p);
void					ft_player_nbr(t_player *player);
int						ft_magic(int fd, char *st);
int						ft_size(int fd, t_player *player,
		char *av, struct s_flags *flags);
void					verb(t_process *p, int r);
void					exe_proc(t_env *env, t_process
		*proc_to_exe);
void					ft_show_pc(int op_code, int b_pc, t_process
		*pro, t_env *env);
void					loop(t_env *env);
void					ft_print_mem(unsigned char *str);
void					ft_free(t_list *p);
int						ft_exec_operations(t_env *env, t_process *proc_to_exe);
int						count_champ(t_player *player);
int						ft_getnumber(unsigned char *str, int ptr, int size);
void					ft_st(t_env *env, t_process *proc);
int						get_short(int a);
int						get_size(int binary, int label);
void					kill_proc(int s, t_env *env, t_process
		*proc_to_kill, t_process **f_proc);
int						count_live(t_process *f_proc);
int						get_t_ind(t_env *env, t_process *proc,
		t_list *params, int p_nbr);
t_param					*get_good_t_param(t_list *params, int p_nbr);
int						get_t_arg(t_env *env, t_process
		*proc, t_list *params, int p_nbr);
t_process				*create_proc(t_env *env);
void					reset_live_proc(t_env *env);
int						count_t_param(t_list *params);
t_list					*get_parameters(t_env *env, t_process *proc);
int						ft_mod(int c);
void					print_hex(unsigned char c);
int						calculate_size(int code, int param_max,
		int label);
void					ft_and(t_env *env, t_process *proc);
int						va(int reg, int dir, int ind, t_param *param);
WINDOW					**init_windows(void);
void					graphical_loop(t_env *env);
void					draw_windows(WINDOW **windows,
		t_env *env, t_loop *loop);
t_loop					*init_loop_params(void);
void					inside_loop(t_loop *loop, t_env *env);
void					init_cycle(t_env *env, t_process *proc);
t_process				*create_new_proc(t_player *player);
void					ft_free(t_list *lst);
void					draw_borders(WINDOW *vin);
void					draw_infos(WINDOW *vin, t_env *env, t_loop *loop);
int						no_coding_byte(int op_code);

#endif
