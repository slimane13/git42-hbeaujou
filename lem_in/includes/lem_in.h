/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 14:20:35 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/08 10:48:10 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../ft_printf/printf/ft_printf.h"
# include "../ft_printf/get_next_line/get_next_line.h"
# include "../ft_printf/libft/libft.h"

typedef struct s_room		t_room;
typedef struct s_map		t_map;
typedef struct s_tun		t_tun;
typedef struct s_path		t_path;
typedef struct s_reseau		t_reseau;

struct			s_path
{
	char		*name;
	int			ant;
	t_path		*next;
	t_path		*previous;
};

struct			s_reseau
{
	int			choix;
	t_reseau	*next;
	t_path		*path;
};

struct			s_tun
{
	char		*name;
	t_tun		*next;
	t_map		*p_map;
};

struct			s_room
{
	char		*name;
	int			start;
	int			end;
	int			x;
	int			y;
	int			from_end;
	int			flag;
	t_tun		*next;
};

struct			s_map
{
	t_map		*next;
	t_room		*room;
};

extern int		g_coups;
extern int		g_after_end;
extern int		g_after_start;
extern int		g_begin_attrib_map;
extern int		g_begin_tunnel;
extern int		g_nb;
extern int		g_lem;
extern int		g_end_affiche;
extern int		g_total;

int				apply_line(char *line, t_map **map, int t_1);
int				read_line(char *line);
int				is_valid_coord(char *line);
int				is_valid_tunnel(char *line);
int				apply_start(char *line, t_map **map);
int				apply_end(char *line, t_map **map);
int				apply_map(char *line, t_map **map);
int				apply_tunnel(char *line, t_map **map);
int				nbr_path(t_map **map);
int				nbr_path_end(t_map **map);
int				nbr_path_start(t_map **map);
int				calc_path_n(t_reseau **res);

void			ft_lstaddend_reseau(t_reseau **alst, t_reseau *new_r);
void			ft_lstaddend_room(t_map **alst, t_map *new_r);
void			ft_lstaddend_path(t_path **alst, t_path *new_r);
void			ft_lstaddend_tun(t_tun **alst, t_tun *new_r);
void			apply_map_to_tun(t_map **map);
void			read_map(t_map **map);
void			path_to_flag(t_path **path, t_map **map, int choix);
void			reseau_to_flag(t_reseau **reseau, t_map **map);
void			clean_flag(t_map **map);
void			clean_from_end(t_map **map);
void			put_fromend(t_map **map);
void			put_fromend_recur(t_map **map, int coups);
void			first_path_finding(t_map **map);
void			path_finding(t_map **map, int nb);
void			build_first_reseau(t_reseau **reseau, t_map **map);
void			build_reseau(t_reseau **reseau, t_map **map, int count);
void			affiche_path(int nb, t_reseau **res);
void			avance_lem(t_reseau **res, int *i, int nb_path);
void			next_to_previous(t_reseau **res);
void			exit_prgm(void);

t_reseau		*new_reseau(int choix, t_path *path);
t_path			*new_path(char *str);
t_path			*fromend_to_path(t_map **tmp);
t_room			*new_room(char *str, int cx, int cy);
t_map			*find_shortest(t_map **tmp);
t_map			*new_map(char *str, int cx, int cy);
t_tun			*new_tun(char *str);

#endif
