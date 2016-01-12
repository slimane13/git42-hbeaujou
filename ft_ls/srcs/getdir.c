/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 05:50:56 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/03 08:25:06 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_getdir(char *argv)
{
	char	*dst;
	char	*temp_argv;
	size_t	i;

	i = ft_strlen(argv) - 1;
	temp_argv = ft_strdup(argv);
	while (i > 0 && temp_argv[i] && temp_argv[i] != '/')
	{
		temp_argv[i] = '\0';
		i--;
	}
	if (i == 0)
		dst = ft_strdup("./");
	else
		dst = ft_strdup(temp_argv);
	return (dst);
}
