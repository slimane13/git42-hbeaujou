/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:43:40 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 13:30:17 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE				13
# define MULTI_MEMORY			2
# define MAX_FD					1000

typedef struct          s_var
{
        char			*memory;
        long			len;
        long			tampon;
        int				file_lecture;
		char			*return_line;
}                       t_var;

int						get_next_line(int fd, char **line);

#endif
