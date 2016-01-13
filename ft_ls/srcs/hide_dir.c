/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hide_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:14:05 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:14:06 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_hide_dir(char *absolute)
{
	int		len;

	len = ft_strlen(absolute);
	while (absolute[len] != '/')
		len--;
	if (absolute[len + 1] == '.')
		return (1);
	return (0);
}
