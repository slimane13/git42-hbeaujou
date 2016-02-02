/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_file_format2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:27:27 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/25 19:42:34 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_to_bytecode.h"

char	is_label_char2(char c)
{
	int		i;

	i = 0;
	while (LABEL_CHARS[i])
	{
		if (LABEL_CHARS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	is_label(char *line)
{
	int		i;

	i = 0;
	if (!(line = ft_strtrim(line)))
		return (0);
	while (line[i])
	{
		if (line[i] == LABEL_CHAR)
		{
			if (i == 0)
				return (0);
			return (1);
		}
		if (!is_label_char2(line[i]))
			return (0);
		i++;
	}
	return (0);
}

char	is_valid_line(char *line, int line_number)
{
	if (ft_strlen(line) > 0)
	{
		if (is_name_descr(line) || is_comment_descr(line) || is_empty_line(line)
			|| is_comment_line(line) || is_command(line) || is_label(line))
			return (1);
		ft_putstr_fd("Line n ", 2);
		ft_putnbr_fd(line_number, 2);
		ft_putendl_fd(" is wrong formated", 2);
		return (0);
	}
	return (1);
}

char	is_command_start(char *line)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (ft_strcmp(g_op_tab[i].name,
						ft_strsub(line, 0, ft_strlen(g_op_tab[i].name))) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	is_command(char *line)
{
	if (!(line = ft_strtrim(line)))
		return (0);
	if (!(line = deblank(line)))
		return (0);
	if (is_command_start(line))
		return (1);
	return (0);
}
