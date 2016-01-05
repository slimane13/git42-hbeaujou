/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:41:46 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/05 13:38:44 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_valid_coord(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 0 && line[i] != ' ')
			return (0);
		if (ft_isdigit(line[i]) == 1 &&
				(line[i + 1] == ' ' || line[i + 1] == '\0'))
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	else
		return (0);
}

int		is_valid_tunnel(char *line)
{
	int		i;
	int		nbr;
	char	**name;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			return (0);
		else if (line[i] == '-')
			nbr++;
		i++;
	}
	if (nbr != 1)
		return (0);
	return (1);
}
