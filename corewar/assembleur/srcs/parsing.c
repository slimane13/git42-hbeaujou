/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 16:36:03 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/02/01 11:42:21 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		g_tmp;
int		g_begin;
int		g_lines_tot;

int		is_label_char(char *str)
{
	char	*label;
	int		i;
	int		j;
	int		len;

	label = ft_strdup(LABEL_CHARS);
	len = ft_strlen(LABEL_CHARS);
	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (label[j])
		{
			if (label[j] == str[i])
				break ;
			j++;
		}
		if (j == len - 1)
			return (0);
		i++;
	}
	return (1);
}

int		cut_cut_cbegin(char *tmp, char *tmp2, int lenn)
{
	tmp2 = ft_strsub(tmp, lenn, ft_strlen(tmp) - 1);
	tmp2 = ft_strtrim(tmp2);
	if (ft_strlen(tmp2) > PROG_NAME_LENGTH)
	{
		ft_printf("Name too big\n");
		exit(0);
	}
	if (tmp2[0] == '"' && tmp2[ft_strlen(tmp2) - 1] == '"')
		return (100);
	else
		return (0);
}

int		check_begin(char *tmp)
{
	char	*tmp2;
	int		lenn;
	int		lenc;

	lenn = ft_strlen(NAME_CMD_STRING);
	lenc = ft_strlen(COMMENT_CMD_STRING);
	tmp2 = ft_strsub(tmp, 0, lenn);
	if (ft_strcmp(tmp2, NAME_CMD_STRING) == 0)
		return (cut_cut_cbegin(tmp, tmp2, lenn));
	tmp2 = ft_strsub(tmp, 0, lenc);
	if (ft_strcmp(tmp2, COMMENT_CMD_STRING) == 0)
	{
		tmp2 = ft_strsub(tmp, lenc, ft_strlen(tmp) - 1);
		tmp2 = ft_strtrim(tmp2);
		if (ft_strlen(tmp2) > COMMENT_LENGTH)
		{
			ft_printf("Comment too big\n");
			exit(0);
		}
		if (tmp2[0] == '"' && tmp2[ft_strlen(tmp2) - 1] == '"')
			return (101);
		else
			return (0);
	}
	return (0);
}

int		check_line(char *line)
{
	char		*tmp;
	char		*test1;
	char		*test2;

	test1 = ft_strdup(NAME_CMD_STRING);
	test2 = ft_strdup(COMMENT_CMD_STRING);
	tmp = ft_strtrim(line);
	if (tmp[0] == test1[0] || tmp[0] == test2[0])
		return (cut_check_begin(tmp));
	else if (tmp[0] == '\0')
		return (103);
	else if (check_name_solo(tmp) == 1)
	{
		if (check_name_double(tmp) == 1)
			return (106);
		return (102);
	}
	else if (is_comment(tmp) == 1)
		return (105);
	else
		return (check_what_is(line));
}

void	add_command(int test, t_function **file, char *line)
{
	t_function	*tmp;

	if (test == 100)
		add_c_name(file, line);
	else if (test == 101)
		add_comment(file, line);
	else if (test == 102)
		cut_parsing_1(file, line);
	else if (test == 106)
		cut_parsing_2(file, line);
	else if (test == 103 || test == 105)
		;
	else if (test == 0)
		;
	else
	{
		if (g_begin != 2)
			exit_prgm_nbr(NULL, NULL);
		if (last_fun_h(file) == 1)
		{
			tmp = new_function(NULL);
			ft_lstaddend_funct(file, tmp);
		}
		cut_parsing_3(file, line, test);
	}
}
