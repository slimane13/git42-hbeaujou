/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:17:29 by ebouther          #+#    #+#             */
/*   Updated: 2015/11/29 14:15:56 by ebouther         ###   ########.fr       */
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
	int			last_x;
	int			last_pos;
}				t_env;

t_map			*ft_get_maps(int fd);

#endif
