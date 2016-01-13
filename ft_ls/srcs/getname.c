/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getname.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:13:54 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:13:54 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_getname(char *argv)
{
	char	*dst;

	if (ft_strrchr(argv, '/') != NULL)
	{
		dst = ft_strrchr(argv, '/');
		return (dst + 1);
	}
	dst = ft_strdup(argv);
	return (dst);
}
