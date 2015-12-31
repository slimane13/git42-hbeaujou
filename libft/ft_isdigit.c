/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:12:58 by dbousque          #+#    #+#             */
/*   Updated: 2015/12/31 15:40:30 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_isalldigit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > '9' && str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int		ft_isfirstdigit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && !ft_isdigit(str[i]))
		i++;
	if (ft_isdigit(str[i]))
		return (str[i] - '0');
	return (0);
}

int		ft_isallnull(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
