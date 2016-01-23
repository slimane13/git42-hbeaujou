/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 16:00:06 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/22 17:37:26 by hbeaujou         ###   ########.fr       */
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
# define LABEL 6

typedef struct s_function	t_function;
typedef struct s_line		t_line;
typedef struct s_instruct	t_instruct;

typedef struct	s_param
{
	char	type;
	int		val;
}				t_param;

typedef struct	s_tempo
{
	char		*tmp2;
	char		*str2;
	char		*name;
	char		*label;
	char		*param1;
	char		*param2;
	char		*param3;
	char		*param4;
	char		*param5;
	char		*param6;
	int			i;
	int			j;
}				t_tempo;

struct			s_function
{
	int			header;
	int			bytes_written;
	char		*label;
	t_line		*lines;
	t_function	*next;
	t_function	*prev;
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

extern int		g_lines_tot;
extern int		g_tmp;
extern int		g_begin;
extern int		g_nb_line;
extern t_op		g_op_tab[17];

char			*deblank(char *input);
char			*rem_com_if(char *str);

int				cut_check_begin(char *tmp);
int				convert_file(char *filename);
int				cant_read_file(char *filename);
int				cant_create_file(char *filename);
int				create_res_file(char *filename, char **filename_res);
int				is_label_char(char *str);
int				check_begin(char *tmp);
int				check_function(char *tmp);
int				check_line(char *line);
int				check_param(char *str);
int				check_name_solo(char *str);
int				check_what_is(char *str);
int				recup_opcode(char *str);
int				str_to_int(char *str);
int				is_number(char *str);
int				the_number(char *str);
int				check_name_double(char *str);
int				is_comment(char *str);
int				is_in_tab(int a, int *tab, int i);
int				last_fun_h(t_function **file);
int				convert_to_bytecode(t_function *functions, char *filename);

void			check_space_label(int i, char *str);
void			cut_parsing_1(t_function **file, char *line);
void			cut_parsing_2(t_function **file, char *line);
void			cut_parsing_3(t_function **file, char *line, int test);
void			cut_check_p1(char *str, char *str2, int *tab, int i);
void			cut_check_p2(char *str, char *str2, int *tab, int i);
void			cut_check_p3(char *str, char *str2, int *tab, int i);
void			cut_1_5_param(t_tempo **vars, int test);
void			cut_2_5_param(t_tempo **vars);
void			cut_1_6_param(t_tempo **vars);
void			cut_2_6_param(t_tempo **vars);
void			cut_param_3(t_tempo **vars, int test);
void			cut_param_4(t_tempo **vars, int test);
void			check_file(t_function **file);
void			check_instruct(t_instruct **content, char *str2);
void			exit_prgm_nbr(char *str, char *str2);
void			exit_prgm_rg_big(char *str, char *str2);
void			exit_prgm_type_rg(char *str, char *str2);
void			exit_prgm_type_ind(char *str, char *str2);
void			exit_prgm_type_dir_l(char *str, char *str2);
void			exit_prgm_type_dir_n(char *str, char *str2);
void			exit_prgm_lab_in(char *str, char *str2);
void			exit_prgm_fk_dir(char *str, char *str2);
void			add_c_name(t_function **file, char *line);
void			add_comment(t_function **file, char *line);
void			add_fun(t_function **file, char *line);
void			add_line_1_param(t_function **file, char *line, int test);
void			add_line_2_param(t_function **file, char *line, int test);
void			add_line_3_param(t_function **file, char *line, int test);
void			add_line_4_param(t_function **file, char *line, int test);
void			add_line_5_param(t_function **file, char *line, int test);
void			add_line_6_param(t_function **file, char *line, int test);
void			add_command(int test, t_function **file, char *line);
void			ft_lstaddend_funct(t_function **alst, t_function *new_r);
void			ft_lstaddend_line(t_line **alst, t_line *new_r);
void			ft_lstaddend_instruct(t_line **alst, t_instruct *new_r);
void			make_line_1(t_function **file, t_tempo *vars);
void			make_line_2(t_function **file, t_tempo *vars);
void			make_line_3(t_function **file, t_tempo *vars);
void			make_line_4(t_function **file, t_tempo *vars);
void			make_line_5(t_function **file, t_tempo *vars);
void			make_line_6(t_function **file, t_tempo *vars);

t_function		*new_function(char *str);
t_line			*new_line(int count);
t_instruct		*new_instruct(char *str, int typ, int opcod);

#endif
