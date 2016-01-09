/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:47:27 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/09 14:53:03 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/printf/ft_printf.h"
#include "../ft_printf/libft/libft.h"
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

typedef struct		s_file t_file;

struct				s_file
{
	t_file			*next;
	char			*name;
	char			*modif;
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
void				affiche_files(t_file **files, t_flag **flags);
void 				affiche_files_acone(t_file **files);
void				modif_names(t_file **files);

int					is_flag(char *str);
int					nbr_files(t_file **files);

t_file				*new_file(char *name);
