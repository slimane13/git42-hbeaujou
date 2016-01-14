/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rajouts1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:01:02 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 17:04:18 by hbeaujou         ###   ########.fr       */
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

char	*ft_makedir(char *argv)
{
	char	*dst;

	dst = ft_strjoin(argv, "/");
	return (dst);
}
