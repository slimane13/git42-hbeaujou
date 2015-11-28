/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:17:29 by ebouther          #+#    #+#             */
/*   Updated: 2015/11/27 17:27:14 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

#include "get_next_line.h"
#include "libft.h"

typedef struct	s_map
{
	int			x;
	int			y;
	char		*content;
	void		*nxt_map;
}				t_map;

t_map	*ft_get_maps(int fd);

#endif
