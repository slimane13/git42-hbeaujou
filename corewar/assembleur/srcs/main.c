/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:46:11 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/22 13:53:48 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		usage_info(void)
{
	ft_putstr("Usage: ./asm <sourcefile>\n");
	return (0);
}

int		cant_read_file(char *filename)
{
	ft_putstr_fd("Can't read source file ", 2);
	ft_putendl_fd(filename, 2);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (usage_info());
	convert_file(argv[argc - 1]);
	return (0);
}
