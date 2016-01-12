/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 09:34:13 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/12 12:06:21 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <dirent.h>
# include <time.h>
# include <string.h>
# include <stdlib.h>
# include "../ft_printf/printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"

# define REVERSE		1
# define RECURSIVE		1
# define HIDE			1
# define SUP_HIDE		1
# define LONG			1
# define COLORS			1
# define LISTED			1
# define PIPE			1
# define STOP			1
# define UID			1
# define LONG_DATE		1

# define NO_REVERSE		0
# define NO_RECURSIVE	0
# define NO_HIDE		0
# define NO_SUP_HIDE	0
# define NO_LONG		0
# define NO_COLORS		0
# define NO_LISTED		0
# define NO_PIPE		0
# define NO_STOP		0
# define NO_UID			0
# define NO_LONG_DATE	0

# define BY_NAME		1
# define BY_TIME		2
# define BY_SIZE		3

# define DATE_MODIF		1
# define DATE_CREATE	2
# define DATE_ACCES		3

# define OUT_ERROR		0
# define OUT_FILES		1
# define OUT_DIR		2

typedef struct	s_len
{
	size_t			links;
	size_t			uid;
	size_t			gid;
	size_t			size;
	size_t			major;
	size_t			minor;
	size_t			maj_min;
	int				dev;
	unsigned long	total_blocks;
	int				nb_files;
}				t_len;

typedef struct	s_option
{
	int		rev;
	int		rec;
	int		by;
	int		prio_by;
	int		hide;
	int		sup_hide;
	int		colors;
	int		format;
	int		listed;
	int		date;
	int		long_date;
	int		pipe;
	int		uid;
	int		stop;
}				t_option;

typedef struct	s_long
{
	char		*uid_name;
	char		*gid_name;
	char		*time;
	char		*linkname;
}				t_long;

typedef struct	s_dir
{
	char			*dossier;
	char			*name;
	char			*absolute;
	struct s_long	*format;
	struct stat		buf;
	struct s_dir	*next;
}				t_dir;

extern char		check;

char			*ft_getdir(char *argv);
char			*ft_getname(char *argv);
char			*ft_makedir(char *argv);
char			*ft_makeabsolute(char *dir, char *file);
int				ft_checkargv(char *argv, t_option *op);
char			***ft_maketab_of_argv(char **argv, int argc, t_option *op);
char			ft_check_option(char const *op, t_option **t_op);
void			ft_previous(char **argv, int argc);
int				*ft_getnb_out(char **argv, int argc, t_option *op);
void			ft_printfile(char **argv, t_option *op, int *nb);
void			ft_putstr_chem(char const *s);
int				ft_hide_dir(char *absolute);
void			ft_sort_params_dir(char **argv, int argc, t_option *op);
int				ft_nbfiles(t_dir **begin, t_option *op);
void			ft_putcolors(t_dir *file, t_option *op);
void			ft_prepar(int argc, char **argv);
t_dir			*ft_lstnew_ls(struct stat buf);
void			ft_lstadd_ls(t_dir **begin_list, struct stat buf);
void			ft_lstsort(t_dir **begin_list, t_option *op);
void			ft_lstswap(t_dir **a, t_dir **b);
void			ft_free_dir(t_dir **begin_list);
t_len			ft_initlen(void);
t_len			ft_format(t_dir **begin, t_option *op);
t_dir			*ft_recup(char *argv, t_option *op);
t_long			*ft_recup_long(struct stat buf, t_option *op);
void			ft_initoption(t_option **t_op);
void			ft_mode(char *argv, mode_t mode);
void			ft_ls_long_or_not(t_dir *file, t_option *op, t_len len);
void			ft_printdir(char *argv, t_option *op);
char			*ft_strjoin_dir(const char *s1, const char *s2);

#endif
