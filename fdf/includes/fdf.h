/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:24:55 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/02/02 11:01:24 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../minilibx_macos/mlx.h"
#include "../ft_printf/printf/ft_printf.h"
#include "../ft_printf/libft/libft.h"
#include "../ft_printf/get_next_line/get_next_line.h"

# define W 13
# define S 1
# define A 0
# define D 2
# define P 35
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125

typedef struct	s_point	t_point;
typedef struct	s_line	t_line;

struct			s_point
{
	t_point		*next;
	int			x;
	int			y;
	int			z;
};

void			ft_lstaddend_point(t_point **alst, t_point *new_r);

int key_hook(int keycode, t_point **begin, void *window, void *init);

t_point			*new_point(int x, int y, int h);
