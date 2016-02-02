/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2016/01/31 19:05:09 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "libdodo.h"

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

# define IND_SIZE				2
# define REG_SIZE				1
# define DIR_SIZE				4

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHARS			"#;"
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(132)
# define COMMENT_LENGTH			(2052)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef char	t_arg_type;

typedef struct		s_player
{
	char			*name;
	char			*comment;
	int				number;
	unsigned char	*code;
	unsigned int	code_len;
	unsigned char	*start;
}					t_player;

typedef struct		s_process
{
	int				number;
	int				*registres;
	unsigned char	*next_instr;
	char			carry;
	int				remaining_cycles;
	int				last_live;
	int				nb_live;
	int				creation_cycle;
	unsigned char	current_opcode;
}					t_process;

typedef struct		s_vm
{
	t_player		**players;
	int				nb_players;
	t_list			*processes;
	unsigned char	*memory;
	int				current_cycle;
	int				last_verif;
	int				last_player;
}					t_vm;

typedef struct		s_op
{
	char			*name;
	int				nb_params;
	int				params_types[MAX_ARGS_NUMBER];
	int				opcode;
	int				nb_cycles;
	char			*comment;
	int				has_param_byte;
	int				small_dir;
	int				(*function)(t_vm *vm, t_process *process, int *params,
																	int len);
}					t_op;

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

extern t_op			g_op_tab[17];

#endif
