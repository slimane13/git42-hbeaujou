/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:18:00 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/08 14:02:26 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int *ret, char *buf, const int fd)
{
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	*ret = read(fd, buffer, BUFF_SIZE);
	buffer[*ret] = '\0';
	if (buf[0] != '\0')
		tmp = ft_strjoin(buf, buffer);
	else
		tmp = ft_strdup(buffer);
	ft_strclr(buf);
	return (tmp);
}

int		get_next_line(int const fd, char **line)
{
	static char		*buf = "";
	int				ret;
	char			*cpy;
	char			*str;

	if (fd < 0 || !line)
		return (-1);
	if (buf[0] == '\0')
		buf = ft_strnew(0);
	*line = ft_strnew(0);
	ret = 1;
	while (ret > 0)
	{
		cpy = read_file(&ret, buf, fd);
		if ((str = ft_strchr(cpy, '\n')) != NULL)
		{
			*str = '\0';
			buf = ft_strdup(str + 1);
			*line = ft_strjoin(*line, cpy);
			return (1);
		}
		*line = ft_strjoin(*line, cpy);
	}
	return (ret);
}
