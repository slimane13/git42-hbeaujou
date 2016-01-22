/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 15:59:39 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/21 14:18:12 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char* deblank(char* input)
{
	int i;
	int j;
	char *output;
	
	output = input;
	i = 0;
	j = 0;
	while (i < ft_strlen(input))
	{
		if (input[i] != ' ' && input[i] != '\t')
			output[j] = input[i];
		else
			j--;
		i++;
		j++;
	}
	output[j] = 0;
	return (output);
}

int				error_while_reading(char *filename)
{
	ft_putstr_fd("Error while reading file ", 2);
	ft_putendl_fd(filename, 2);
	return (0);
}

void	affiche(t_function **file)
{
	t_function	*tmp;
	t_line		*tmp2;
	t_instruct	*tmp3;

	tmp = *file;
	while (tmp)
	{
		ft_printf("nom : %s\n", tmp->label);
		tmp2 = tmp->lines;
		while (tmp2)
		{
			tmp3 = tmp2->content;
			while (tmp3)
			{
				ft_printf("instruct : %s\n", tmp3->name);
				tmp3 = tmp3->next;
			}
			ft_printf("\n");
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
//lol
int				convert_file(char *filename)
{
	t_function *file;
	char		*line;
	int			ret;
	int			fd;
	int			test;

	g_begin = 0;
	g_lines_tot = 0;
	file = NULL;
	fd = open(filename, O_RDONLY);
	if (fd <= -1)
		return (cant_read_file(filename));
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		test = check_line(line);
		add_command(test, &file, line);
		g_lines_tot++;
	}
	if (ret == -1)
		return (error_while_reading(filename));
//	affiche(&file);
	check_file(&file);
	convert_to_bytecode(file, filename);
	return (0);
}
