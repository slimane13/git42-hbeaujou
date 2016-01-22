/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:46:11 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/19 14:54:24 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		usage_info(void)
{
	ft_putstr("Usage: ./asm <sourcefile>\n");
	//ft_putstr("-a : Instead of creating a .cor file, outputs a stripped and");
	//ft_putendl(" annotated version of the code to the standard output");
	return (0);
}

int		cant_read_file(char *filename)
{
	ft_putstr_fd("Can't read source file ", 2);
	ft_putendl_fd(filename, 2);
	return (0);
}

/*int		cant_create_file(char *filename)
{
	ft_putstr_fd("Failed to create binary file ", 2);
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
	int		fd;
	int		last_point;

	last_point = get_last_point_index(filename);
	if (!(*filename_res = (char*)malloc(sizeof(char) * (last_point + 5))))
		return (0);
	(*filename_res)[last_point + 4] = '\0';
	ft_memcpy(*filename_res, filename, last_point);
	(*filename_res)[last_point] = '.';
	(*filename_res)[last_point + 1] = 'c';
	(*filename_res)[last_point + 2] = 'o';
	(*filename_res)[last_point + 3] = 'r';
	return (open(*filename_res, O_CREAT | O_TRUNC | O_RDWR));
}*/

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (usage_info());
	convert_file(argv[argc - 1]);
	return (0);
}
