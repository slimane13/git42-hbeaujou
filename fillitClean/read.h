/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:17:29 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/09 14:22:35 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
# include "get_next_line.h"
# include "libft.h"

typedef struct	s_map
{
	int			x;
	int			y;
	char		*content;
	void		*nxt_map;
}				t_map;

typedef struct	s_env
{
	int			nb_of_line;
	int			last_x;
	int			last_pos;
}				t_env;

t_map			*ft_get_maps(int fd, int tetriminos);
void			ft_error_exit(void);
char			*ft_add_to_line(int tetriminos);
char			*ft_add_to_map(int tetriminos);
void			ft_check_tetriminos(t_map *map, int tetriminos);

#endif
