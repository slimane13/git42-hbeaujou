/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:08:43 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 17:08:44 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define BUF_SIZE		1
# define MULTI_MEMORY		2
# define MAX_FD			1000

typedef struct		s_var_3
{
	char			*return_line;
	char			*memory;
	long			len;
	long			tampon;
	int				file_lecture;
}					t_var_3;

int					get_next_line(int fd, char **line);

#endif
