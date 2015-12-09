/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 20:21:39 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/09 15:03:07 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"


char		*ft_add_to_line(int tetriminos)
{
	char	*ret;

	if (!(ret = ft_strnew(0)))
		ft_error_exit();
	if (tetriminos <= 2)
		return (ret);
	while (tetriminos - 4)
	{
		ret = ft_strjoin(ret, ft_strdup("."));
		tetriminos--;
	}
	return (ret);
}

char		*ft_add_to_map(int tetriminos)
{
	char	*ret;
	int		i;

	i = tetriminos - 4;
	if (!(ret = ft_strnew(0)))
		ft_error_exit();
	if (tetriminos <= 2)
		return (ret);
	while (i--)
		ret = ft_strjoin(ret, ft_strjoin(ft_add_to_line(tetriminos + 4), ft_strdup("\n")));
	return (ret);
}



static void	ft_check_tetriminos_1(char *content, int tetriminos)
{
	if (tetriminos <= 2)
		tetriminos = 4;
	if (!((content[tetriminos + 1] == '#' && content[tetriminos] == '#' && content[tetriminos + 2] == '#')
				|| (content[tetriminos + 1] == '#' && content[tetriminos + 2] == '#' && content[(tetriminos + 1) * 2] == '#')
				|| (content[tetriminos + 1] == '#' && content[tetriminos] == '#' && content[(tetriminos + 1) * 2] == '#')
				|| (content[tetriminos + 1] == '#' && content[tetriminos + 2] == '#' && content[tetriminos + 3] == '#')
				|| (content[tetriminos + 1] == '#' && content[(tetriminos + 1) * 2] == '#' && content[((tetriminos + 1) * 2) + 1] == '#')
				|| (content[tetriminos + 1] == '#' && content[tetriminos + 1 - 1] == '#' && content[(tetriminos + 1) - 2] == '#')
				|| (content[tetriminos + 1] == '#' && content[(tetriminos + 1) * 2] == '#' && content[(tetriminos + 1) * 2 - 1] == '#')
				|| (content[1] == '#' && content[2] == '#' && content[(tetriminos + 1) + 2] == '#')
				|| (content[1] == '#' && content[2] == '#' && content[tetriminos + 1] == '#')
				|| (content[tetriminos + 1] == '#' && content[(tetriminos + 1) * 2] == '#' && content[1] == '#')
				|| (content[tetriminos + 2] == '#' && content[(tetriminos + 1) * 2 + 1] == '#' && content[1] == '#')
				|| (content[tetriminos + 1] == '#' && content[(tetriminos + 1) * 2] == '#' && content[(tetriminos + 1) * 3] == '#')
				|| (content[1] == '#' && content[2] == '#' && content[3] == '#')
				|| (content[1] == '#' && content[2] == '#' && content[tetriminos + 2] == '#')
				|| (content[1] == '#' && content[tetriminos + 1] == '#' && content[tetriminos + 2] == '#')
				|| (content[1] == '#' && content[tetriminos] == '#' && content[tetriminos + 1] == '#')
				|| (content[1] == '#' && content[tetriminos] == '#' && content[tetriminos + 1] == '#')
				|| (content[tetriminos + 1] == '#' && content[tetriminos + 2] == '#' && content[(tetriminos + 1) * 2 + 1] == '#')
				|| (content[tetriminos + 1] == '#' && content[tetriminos] == '#' && content[(tetriminos + 1) * 2 - 1] == '#')
				|| (content[1] == '#' && content[tetriminos + 2] == '#' && content[tetriminos + 3] == '#')))
		ft_error_exit();
}

void		ft_check_tetriminos(t_map *map, int tetriminos)
{
	char	*content;
	int		i;
	int		occur;

	i = 0;
	occur = 0;
	content = map->content;
	while (content[i])
	{
		if (content[i] != '.' && content[i] != '#' && content[i] != '\n')
			ft_error_exit();
		if (content[i] == '#')
		{
			if (occur == 0)
				ft_check_tetriminos_1(content + i, tetriminos);
			occur++;
		}
		i++;
	}
	if (occur != 4)
		ft_error_exit();
}
