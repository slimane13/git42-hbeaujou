/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_file_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:26:02 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/25 19:42:43 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_to_bytecode.h"

char	is_name_descr(char *line)
{
	int		i;
	char	*ori_line;

	if (!(line = ft_strtrim(line)))
		return (0);
	if (!(line = deblank(line)))
		return (0);
	if (ft_strlen(line) < ft_strlen(NAME_CMD_STRING))
		return (0);
	ori_line = ft_strdup(line);
	line[ft_strlen(NAME_CMD_STRING)] = '\0';
	if (!ft_strcmp(line, NAME_CMD_STRING) == 0)
		return (0);
	i = ft_strlen(NAME_CMD_STRING) + 1;
	if (ori_line[i - 1] != '"')
		return (0);
	while (ori_line[i] && ori_line[i] != '"')
		i++;
	if (ori_line[i] != '"' || ori_line[i + 1])
		return (0);
	return (1);
}

char	is_comment_descr(char *line)
{
	int		i;
	char	*ori_line;

	if (!(line = ft_strtrim(line)))
		return (0);
	if (!(line = deblank(line)))
		return (0);
	if (ft_strlen(line) < ft_strlen(COMMENT_CMD_STRING))
		return (0);
	ori_line = ft_strdup(line);
	line[ft_strlen(COMMENT_CMD_STRING)] = '\0';
	if (!ft_strcmp(line, COMMENT_CMD_STRING) == 0)
		return (0);
	i = ft_strlen(COMMENT_CMD_STRING) + 1;
	if (ori_line[i - 1] != '"')
		return (0);
	while (ori_line[i] && ori_line[i] != '"')
		i++;
	if (ori_line[i] != '"' || ori_line[i + 1])
		return (0);
	return (1);
}

char	is_comment_char(char c)
{
	int		i;

	i = 0;
	while (COMMENT_CHARS[i])
	{
		if (COMMENT_CHARS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	is_comment_line(char *line)
{
	if (!(line = ft_strtrim(line)))
		return (0);
	if (!(line = deblank(line)))
		return (0);
	if (is_comment_char(line[0]))
		return (1);
	return (0);
}

char	is_empty_line(char *line)
{
	if (!(line = ft_strtrim(line)))
		return (0);
	if (!(line = deblank(line)))
		return (0);
	if (ft_strlen(line) == 0)
		return (1);
	return (0);
}
