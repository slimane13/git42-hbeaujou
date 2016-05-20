/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 00:16:20 by sksourou          #+#    #+#             */
/*   Updated: 2015/10/20 16:49:35 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define ABS(x) ((x) < 0 ? (-x) : (x));

/*
** ENV
*/
# define WIN_X 1280
# define WIN_Y 1280
# define WIN_NAME "FDF"

/*
** LISTS
*/
typedef struct		s_all
{
	void			*mlx;
	void			*win;
	int				**nbr;
	int				nbr_line;
	int				*nbr_split;
	int				a;
	int				scalx;
	int				scaly;
	int				startx;
	int				x1;
	int				starty;
	char			**split;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				i;
	int				j;
	int				k;
	char			*line;
	int				incx;
	int				incy;

}					t_all;
/*
** tools
*/
void				init(t_all *all);
int					ft_count_split(char **split);
char				*all_to_space(char *str);
void				ft_count_line(t_all *a, int fd);
int					ft_getnbr(char *str);
/*
** hook
*/
int					key_hook(int keycode, t_all *a);
int					get_hook(t_all *a);
void				change_scale(t_all *all, int i);
int					key_hook(int keycode, t_all *all);
/*
** Draw
*/
int					coord_x(t_all *all, int x, int y);
int					get_color(int z1, int z2);
void				draw_y(t_all *all);
void				draw_x(t_all *all);
/*
** Bresenham
*/
void				bh_dispatch(t_all *all, int color);
void				m_neg(t_all *all, int color);
void				m_pos(t_all *all, int color);
#endif
