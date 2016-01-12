/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:13:58 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:13:59 by hbeaujou         ###   ########.fr       */
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
