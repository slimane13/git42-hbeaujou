/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 09:12:40 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 13:42:03 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int    return_line(t_var *vari)
{
	while (vari->tampon > vari->return_line - vari->memory
			&& *(vari->return_line) != '\n')
		vari->return_line++;
	if (*(vari->return_line) == '\n')
		return (vari->tampon > vari->return_line - vari->memory);
	return (0);
}

static int    add_memory_size(t_var *vari)
{
	char  *new_memory;
	long  new_size;

	new_size = vari->len * MULTI_MEMORY;
	if (new_size < vari->len + BUFF_SIZE)
		new_size += BUFF_SIZE;
	new_memory = malloc((new_size + 1) * sizeof(char));
	if (!new_memory)
		return (1);
	ft_strcpy(new_memory, vari->memory);
	new_memory[new_size] = '\0';
	vari->return_line = new_memory + (vari->return_line - vari->memory);
	free(vari->memory);
	vari->memory = new_memory;
	vari->len = new_size;
	return (0);
}

static int		define(t_var **vari)
{
	*vari = malloc(sizeof(t_var));
	if (!*vari)
		return (1);
	(*vari)->len = BUFF_SIZE;
	(*vari)->memory = malloc(((*vari)->len + 1) * sizeof(char));
	if (!(*vari)->memory)
		return (1);
	(*vari)->memory[(*vari)->len] = '\0';
	(*vari)->tampon = 0;
	(*vari)->return_line = (*vari)->memory;
	(*vari)->file_lecture = 1;
	return (0);
}

static int		return_handler(t_var **pointer_to_vari,
		t_var *vari, char **line)
{
	if (vari->return_line < 0)
		return (-1);
	*line = ft_strsub(vari->memory, 0, vari->return_line - vari->memory);
	if ((vari->file_lecture <= 0 || vari->tampon <= 0))
	{
		if (vari->memory)
			free(vari->memory);
		free(vari);
		*pointer_to_vari = NULL;
		return (0);
	}
	vari->tampon = vari->tampon + vari->memory - vari->return_line
		- (vari->file_lecture > 0
			&& *(vari->return_line) == '\n'
			&& vari->tampon != vari->return_line - vari->memory);
	ft_memcpy(vari->memory, vari->return_line + 1, vari->tampon);
	vari->return_line = vari->memory;
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_var	*varis[MAX_FD];

	if (fd >= MAX_FD || fd < 0 || line == NULL)
		return (-1);
	if (varis[fd] && varis[fd]->file_lecture == 0)
		return (0);
	if (!varis[fd] && define(&varis[fd]))
		return (-1);
	while (varis[fd]->file_lecture > 0 && !((return_line(varis[fd]))))
	{
		while (varis[fd]->tampon + BUFF_SIZE > varis[fd]->len)
			if (add_memory_size(varis[fd]))
				return (-1);
		varis[fd]->file_lecture = read(fd, varis[fd]->memory + varis[fd]->tampon
									, BUFF_SIZE);
		varis[fd]->tampon = varis[fd]->tampon + varis[fd]->file_lecture;
	}
	return (return_handler(&varis[fd], varis[fd], line));
}
