/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_bytecode_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:56:50 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/20 18:10:41 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_to_bytecode.h"

int		cant_create_file(char *filename)
{
	ft_putstr_fd("Failed to create binary file ", 2);
	if (filename)
		ft_putendl_fd(filename, 2);
	return (0);
}

int		get_last_point_index(char *filename)
{
	int		i;
	int		ind;

	ind = -1;
	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
			ind = i;
		i++;
	}
	if (ind == -1)
		return (i);
	return (ind);
}

int		create_res_file(char *filename, char **filename_res)
{
	int		last_point;

	last_point = get_last_point_index(filename);
	if (!(*filename_res = (char*)malloc(sizeof(char) * (last_point + 5))))
		return (-1);
	(*filename_res)[last_point + 4] = '\0';
	ft_memcpy(*filename_res, filename, last_point);
	(*filename_res)[last_point] = '.';
	(*filename_res)[last_point + 1] = 'c';
	(*filename_res)[last_point + 2] = 'o';
	(*filename_res)[last_point + 3] = 'r';
	return (open(*filename_res, O_CREAT | O_TRUNC | O_RDWR, 0600));
}

int			write_bytes_to_file(char *filename, t_list *bytes)
{
	int		fd;
	char	**res_filename;
	int		i;

	if (!(res_filename = (char**)malloc(sizeof(char*))))
		return (cant_create_file(NULL));
	*res_filename = NULL;
	if ((fd = create_res_file(filename, res_filename)) == -1)
		return (cant_create_file(*res_filename));
	ft_printf("Writing output program to %s\n", *res_filename);
	while (bytes)
	{
//		ft_putendl("BYTE!");
		//ft_printf("%d\n", *(unsigned char*)bytes->content);
		i = bytes->content_size - 1;
		while (i >= 0)
		{
			write(fd, bytes->content + i, 1);
			i--;
		}
		//write(fd, bytes->content, bytes->content_size);
		bytes = bytes->next;
	}
	return (0);
}

int			big_error(void)
{
	ft_putendl_fd("BIG ERROR", 2);
	return (0);
}

void		*big_error_null(void)
{
	ft_putendl_fd("BIG ERROR", 2);
	return (NULL);
}
