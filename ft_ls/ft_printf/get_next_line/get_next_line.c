/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 09:26:55 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/07 12:26:03 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		define(p_var **vari)
{
	*vari = malloc(sizeof(p_var));
	if (!*vari)
		return (0);
	(*vari)->len = BUF_SIZE;
	(*vari)->memory = malloc(((*vari)->len + 1) * sizeof(char));
	if (!(*vari)->memory)
		return (0);
	(*vari)->memory[(*vari)->len] = '\0';
	(*vari)->tampon = 0;
	(*vari)->return_line = (*vari)->memory;
	(*vari)->file_lecture = 1;
	return (1);
}

static int		add_memory_size(p_var *vari)
{
	char		*new_memory;
	long		new_size;

	new_size = vari->len * MULTI_MEMORY;
	if (new_size < vari->len + BUF_SIZE)
		new_size += BUF_SIZE;
	new_memory = malloc((new_size + 1) * sizeof(char));
	if (!new_memory)
		return (0);
	ft_strcpy(new_memory, vari->memory);
	new_memory[new_size] = '\0';
	vari->return_line = new_memory + (vari->return_line - vari->memory);
	free(vari->memory);
	vari->memory = new_memory;
	vari->len = new_size;
	return (1);
}

static int		return_handle(p_var **pointer_to_vari
									, p_var *vari, char **line)
{
	if (vari->file_lecture < 0)
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
	vari->tampon += vari->memory - vari->return_line
		- (vari->file_lecture > 0
			&& *(vari->return_line) == '\n'
			&& vari->tampon != vari->return_line - vari->memory);
	ft_memcpy(vari->memory, vari->return_line + 1, vari->tampon);
	vari->return_line = vari->memory;
	return (1);
}

static int		return_line(p_var *vari)
{
	while (vari->tampon > vari->return_line - vari->memory
			&& *(vari->return_line) != '\n')
		vari->return_line++;
	if (*(vari->return_line) == '\n')
		return (vari->tampon > vari->return_line - vari->memory);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static p_var	*get_in[MAX_FD];

	if (fd >= MAX_FD || fd < 0 || line == NULL)
		return (-1);
	if (get_in[fd] && get_in[fd]->file_lecture == 0)
		return (0);
	if (!get_in[fd] && !define(&get_in[fd]))
		return (-1);
	while (get_in[fd]->file_lecture > 0 && !((return_line(get_in[fd]))))
	{
		while (get_in[fd]->tampon + BUF_SIZE > get_in[fd]->len)
			if (!add_memory_size(get_in[fd]))
				return (-1);
		get_in[fd]->file_lecture = read(fd, get_in[fd]->memory + get_in[fd]->tampon, BUF_SIZE);
		get_in[fd]->tampon = get_in[fd]->tampon + get_in[fd]->file_lecture;
	}
	return (return_handle(&get_in[fd], get_in[fd], line));
}
