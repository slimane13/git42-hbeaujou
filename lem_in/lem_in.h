/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 14:20:35 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/04 16:42:38 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./ft_printf/printf/ft_printf.h"
# include "./ft_printf/get_next_line/get_next_line.h"
# include "./ft_printf/libft/libft.h"

typedef struct	s_room t_room;

struct			s_room
{
	char		*name;
	int			start;
	int			end;
	int			x;
	int			y;
	int			from_end;
	int			flag;
	int			ant;
	t_room		*next;
	t_room		*t_nexts;
	t_room		*t_previous;
};

extern int		g_coups;
extern int		g_after_end;
extern int		g_after_start;
extern int		g_begin_attrib_map;
extern int		g_begin_tunnel;
extern int		g_nb;

int				apply_line(char *line, t_room **map, int t_1);
int				read_line(char *line);
int				is_valid_coord(char *line);
int				is_valid_tunnel(char *line);
int				apply_start(char *line, t_room **map);
int				apply_end(char *line, t_room **map);
int				apply_map(char *line, t_room **map);
int				apply_tunnel(char *line, t_room **map);

void			ft_lstaddend_room(t_room **alst, t_room *new_r);
void			read_map(t_room **map);

t_room			*new_room(char *str, int cx, int cy);

#endif
