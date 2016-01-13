/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 09:34:13 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:54:11 by hbeaujou         ###   ########.fr       */
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

# define CUT01 "../../System/Library/Frameworks/Python."
# define CUT02 "framework/Versions/2.7/bin/2to3-2.7"
# define CUT1 ft_strjoin(CUT11, CUT12)
# define CUT2 "/System/Library/Filesystems/acfs.fs/Contents/bin/cvcp"
# define CUT31 "/System/Library/Frameworks/JavaVM."
# define CUT32 "framework/Versions/Current/Commands/jvisualvm"
# define CUT3 ft_strjoin(CUT31, CUT32)
# define CUT41 "/System/Library/Frameworks/JavaVM."
# define CUT42 "framework/Versions/Current/Commands/javac"
# define CUT4 ft_strjoin(CUT41, CUT42)
# define CUT51 "/System/Library/Frameworks/JavaVM."
# define CUT52 "framework/Versions/Current/Commands/orbd"
# define CUT5 ft_strjoin(CUT51, CUT52)
# define CUT61 "../../System/Library/Frameworks/ApplicationServices."
# define CUT62 "framework/Versions/A/Frameworks/ATS."
# define CUT63 "framework/Versions/A/Support/fontmover"
# define CUT6 ft_strjoin(ft_strjoin(CUT61, CUT62), CUT63)
# define CUT71 "../../System/Library/Frameworks/Python."
# define CUT72 "framework/Versions/2.6/bin/idle2.6"
# define CUT7 ft_strjoin(CUT71, CUT72)
# define CUT81 "../../System/Library/Frameworks/Python."
# define CUT82 "framework/Versions/2.7/bin/idle2.7"
# define CUT8 ft_strjoin(CUT81, CUT82)
# define CUT91 "/System/Library/Frameworks/JavaVM."
# define CUT92 "framework/Versions/Current/Commands/pack200"
# define CUT9 ft_strjoin(CUT91, CUT92)
# define CUT101 "/System/Library/Frameworks/JavaVM."
# define CUT102 "framework/Versions/Current/Commands/javadoc"
# define CUT10 ft_strjoin(CUT101, CUT102)
# define CUT111 "/System/Library/Frameworks/JavaVM."
# define CUT112 "framework/Versions/Current/Commands/keytool"
# define CUT11 ft_strjoin(CUT111, CUT112)
# define CUT121 "/System/Library/Filesystems/acfs."
# define CUT122 "fs/Contents/bin/cvmkdir"
# define CUT12 ft_strjoin(CUT121, CUT122)
# define CUT131 "../../System/Library/Frameworks/Python."
# define CUT132 "framework/Versions/2.6/bin/2to32.6"
# define CUT13 ft_strjoin(CUT131, CUT132)

# define AR1 ft_strcmp(argv[i], "--") != 0
# define AR2 ft_strcmp(argv[i], "---") != 0
# define AR3 ft_strcmp(argv[i], "-file") != 0
# define AR4 ft_strcmp(argv[i], "--file") != 0
# define AR5 ft_strcmp(argv[i], "---file") != 0
# define AR6 ft_strcmp(argv[i], "-dir") != 0
# define AR7 ft_strcmp(argv[i], "--dir") != 0
# define AR8 ft_strcmp(argv[i], "---dir") != 0

typedef struct s_error	t_error;

struct			s_error
{
	char		*name;
	t_error		*next;
};

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

extern char		*g_str;
extern char		g_check;
extern int		g_error1;
extern int		g_error2;
extern t_error	*g_lst;

void			cut_check(t_error *tmp, char *argv, int *test);
void			ft_error(char *argv, int first);
void			ft_lstaddend_error(t_error *new_r);
char			*ft_getdir(char *argv);
void			ft_ls(char **argv, int argc);
void			info_cut3(int count[9], t_dir **f);
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
void			ft_print_long(t_dir *file, t_len len, t_option *op, size_t u);
void			ft_print_long_2(t_dir *file, t_option *op, t_len len, int *p);
void			ft_ls_long_or_not(t_dir *file, t_option *op, t_len len);
void			ft_printdir(char *argv, t_option *op);
char			*ft_strjoin_dir(const char *s1, const char *s2);

#endif
