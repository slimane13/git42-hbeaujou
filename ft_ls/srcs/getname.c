/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 05:51:41 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/01 06:48:55 by bsautron         ###   ########.fr       */
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
