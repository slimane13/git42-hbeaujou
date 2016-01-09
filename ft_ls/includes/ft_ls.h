/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:47:27 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/09 19:28:39 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LS_H
# define FT_LS_H

# include "../ft_printf/printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

# define FL flags->f_l
# define FRM flags->f_R_maj
# define FA flags->f_a
# define FR flags->f_r_min
# define FT flags->f_t
# define FU flags->f_u
# define FF flags->f_f
# define FG flags->f_g
# define FD flags->f_d

# define EFL (*flags)->f_l
# define EFRM (*flags)->f_R_maj
# define EFA (*flags)->f_a
# define EFR (*flags)->f_r_min
# define EFT (*flags)->f_t
# define EFU (*flags)->f_u
# define EFF (*flags)->f_f
# define EFG (*flags)->f_g
# define EFD (*flags)->f_d

typedef struct		s_file t_file;

struct				s_file
{
	t_file			*next;
	t_file			*previous;
	char			*name;
	char			*modif;
	char			*modif2;
	struct stat		stats;
};

typedef struct		s_flag
{
	int				f_l;
	int				f_R_maj;
	int				f_a;
	int				f_r_min;
	int				f_t;
	int				f_u;
	int				f_f;
	int				f_g;
	int				f_d;
}					t_flag;

void				ft_lstaddend_file(t_file **alst, t_file *new_r);
void				parsing(char **av, t_flag **flag, t_file **files);
void				attrib_flag(char *str, t_flag **flag);
void				affiche_column(t_file **files, t_flag **flags);
void 				affiche_files_acone(t_file **files);
void				modif_names(t_file **files);
void				parsing_one(char **av, t_flag **flag);
void				size_to_modif2(t_file **files, int max);
void				argc_one(t_file **files, t_flag **flags, char *str);
void				into_dir(t_file **files, t_flag **flags, char *str);
void				next_to_previous(t_file **files);
void				tri_name(t_file **files);

int					is_flag(char *str);
int					max_len_2(t_file **files);
int					nbr_files(t_file **files);
int					ft_ls(int ac, char **av);

t_file				*new_file(char *name, struct stat *sb);
void				tri_rev(t_file **files);

#endif
