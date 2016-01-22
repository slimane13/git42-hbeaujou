/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 16:00:06 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/18 13:40:20 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libdodo.h"
# include "op.h"
# include <fcntl.h>

# define OPCODE 1
# define INDIR 2
# define DIRE 3
# define HEADER 4
# define REG 5

typedef struct s_function	t_function;
typedef struct s_line		t_line;
typedef struct s_instruct	t_instruct;

typedef struct	s_tempo
{
	char		*tmp2;
	char		*name;
	char		*label;
	char		*param1;
	char		*param2;
	char		*param3;
}				t_tempo;

struct			s_function
{
	int			header;
	int			bytes_written;
	char		*label;
	t_line		*lines;
	t_function  *next;
};

struct			s_line
{
	int			numero;
	t_instruct	*content;
	t_line		*next;
};

struct			s_instruct
{
	char		*name;
	int			type;
	int			opcode;
	t_instruct	*next;
};

extern t_op		op_tab[17];

int				convert_file(char *filename);
int				cant_read_file(char *filename);
int				cant_create_file(char *filename);
int				create_res_file(char *filename, char **filename_res);
int				check_params(char *tmp);
int				is_label_char(char *str);
int				check_begin(char *tmp);
int				check_function(char *tmp);
int				check_line(char *line);

void	add_command(int test, t_function **file);

#endif
