#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define BUF_SIZE		1
# define MULTI_MEMORY		2
# define MAX_FD			1000

typedef struct		o_var
{
	char			*return_line;
	char			*memory;
	long			len;
	long			tampon;
	int				file_lecture;
}					p_var;

int					get_next_line(int fd, char **line);

#endif
