/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:24:55 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/08 12:55:28 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../minilibx_macos/mlx.h"
#include "../ft_printf/printf/ft_printf.h"
#include "../ft_printf/libft/libft.h"
#include "../ft_printf/get_next_line/get_next_line.h"

typedef struct	s_point	t_point;
typedef struct	s_line	t_line;

struct			s_point
{
	t_point		*next;
	int			x;
	int			y;
	int			h;
};

struct			s_line
{
	t_line		*next;
	t_point		*line;
};

void			ft_lstaddend_point(t_point **alst, t_point *new_r);
void			ft_lstaddend_line(t_line **alst, t_line *new_r);

t_point			*new_point(int x, int y, int h);
t_line			*new_line(t_point *tp);
