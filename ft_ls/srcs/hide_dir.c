/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hide_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 06:14:40 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/01 06:15:09 by bsautron         ###   ########.fr       */
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
