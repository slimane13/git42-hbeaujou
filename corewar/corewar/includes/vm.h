/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:03:43 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 16:44:35 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libdodo.h"
# include "op.h"
# include <fcntl.h>

# define PRINT_INSTR 0

extern int		g_error;

typedef struct	s_magic
{
	int			i;
	int			j;
	int			k;
	int			m;
	int			total;
	size_t		res;
}				t_magic;

typedef struct	s_params
{
	int			*params;
	int			*params_length;
}				t_params;

t_vm			*init_vm(void);
void			go_to_next_byte(t_vm *vm, t_process *process);
unsigned char	*next_byte_nb(t_vm *vm, unsigned char *byte, int nb);
int				ft_pow(int nb, int pui);
void			dumpmemory(unsigned char *memory);
int				get_cycles_for_opcode(int opcode);
unsigned char	*next_instr(t_vm *vm, unsigned char *current_instr);
t_process		*new_process(unsigned char *start, int creation_cycle);
void			parse_params(t_vm *vm, unsigned char *str, t_params *params,
																		int nb);
void			print_memory(const void *addr, size_t size);
int				op_live(t_vm *vm, t_process *process, int *params, int len);
int				op_ld(t_vm *vm, t_process *process, int *params, int len);
int				op_st(t_vm *vm, t_process *process, int *params, int len);
int				op_add(t_vm *vm, t_process *process, int *params, int len);
int				op_sub(t_vm *vm, t_process *process, int *params, int len);
int				op_and(t_vm *vm, t_process *process, int *params, int len);
int				op_or(t_vm *vm, t_process *process, int *params, int len);
int				op_xor(t_vm *vm, t_process *process, int *params, int len);
int				op_zjmp(t_vm *vm, t_process *process, int *params, int len);
int				op_ldi(t_vm *vm, t_process *process, int *params, int len);
int				op_sti(t_vm *vm, t_process *process, int *params, int len);
int				op_fork(t_vm *vm, t_process *process, int *params, int len);
int				op_lld(t_vm *vm, t_process *process, int *params, int len);
int				op_lldi(t_vm *vm, t_process *process, int *params, int len);
int				op_lfork(t_vm *vm, t_process *process, int *params, int len);
int				op_aff(t_vm *vm, t_process *process, int *params, int len);
t_process		*new_process(unsigned char *start, int cycle_creation);
int				to_little(int n);
int				verify_file(char *contents, int size);
char			*get_file_content(char *filename, int *res_size);
t_player		*get_player_from_file(t_vm *vm, char *content,
												int content_len, int number);
void			add_player_to_vm(t_vm *vm, t_player *player);
void			dumpmemory(unsigned char *memory);
void			load_players_in_memory(t_vm *vm);
t_vm			*init_vm(void);
int				get_cycles_for_opcode(int opcode);
int				create_start_processes(t_vm *vm);
void			update_cycle_to_die(int total_nb_live, int *cycle_to_die,
												int *to_die_iter, int *checks);
void			remove_from_list(t_vm *vm, t_list *parent, t_list *tmp);
void			delete_dead_processes(t_vm *vm, int *to_die_iter,
												int *cycle_to_die, int *checks);
void			increment_next_instr(t_vm *vm, t_process *process, int nb);
void			go_to_next_byte(t_vm *vm, t_process *process);
char			valid_opcode(unsigned char *opcode);
char			opcode_has_param_byte(unsigned char opcode);
t_op			*get_opcode_descr_with_opcode(unsigned char opcode);
int				is_in_tab(int a, int *tab, int i);
char			valid_param_byte(unsigned char *param_byte,
														unsigned char opcode);
unsigned char	*next_instr(t_vm *vm, unsigned char *current_instr);
int				get_length_of_type(t_op *opcode_descr, unsigned char type);
unsigned char	t_to_code(unsigned char t);
void			get_params_length(int *params_length, t_op *opcode_descr,
													unsigned char *param_byte);
int				add_lengths(int *params_length, int nb);
int				execute_param_byte(t_vm *vm, t_process *process);
int				execute_no_param_byte(t_vm *vm, t_process *process);
char			opcode_is_not_zjmp(char opcode);
void			handle_invalid_param_byte(t_vm *vm, t_process *process,
														unsigned char *opcode);
void			execute_instruction(t_vm *vm, t_process *process);
void			update_instructions(t_vm *vm);
void			execute_processes(t_vm *vm);
void			decrement_cycle_to_die(int *cycle_to_die, int *to_die_iter,
																int *checks);
void			init_vars(int *cycle_to_die, int *to_die_iter, int *checks);
int				run_vm(t_vm *vm, int dump);
t_player		*get_player_with_number(t_vm *vm, int numb);
void			print_winner(t_vm *vm);
void			add_champion(char *filename, t_vm *vm, int n);
int				get_num(char *str, int can_be_neg);
int				validate(int number, t_vm *vm, int *current_num);
void			parse_args(int argc, char **argv, t_vm *vm, int *dump);
void			free_vm(t_vm *vm);
int				get_val_of_n_param(t_vm *vm, t_process *process, int *params,
																		int n);
char			*print_val(int val, int is_reg);
unsigned char	*get_real_addr_of_ind(t_vm *vm, unsigned char *ori_addr,
													int to_add, char modulo);
unsigned int	get_val_at(t_vm *vm, unsigned char *addr, int nb);
char			*get_name_of_opcode(char opcode);
char			valid_reg(int param);
int				type_of_n_param(t_vm *vm, t_process *process, int n);
int				get_modulo_even_neg(int val);
void			copy_val_at(t_vm *vm, unsigned char *addr,
													unsigned int val, int nb);
int				*copy_regs(int *registres);

#endif
