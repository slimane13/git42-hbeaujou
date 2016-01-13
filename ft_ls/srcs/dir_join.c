/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:12:42 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:12:43 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strjoin_dir(const char *s1, const char *s2)
{
	int		len_all;
	char	*dst;
	char	*temp_s1;

	temp_s1 = (char *)s1;
	if (s1 && s2)
	{
		temp_s1 = ft_strjoin(s1, "/");
		len_all = ft_strlen(s1) + ft_strlen(s2);
		dst = ft_memalloc(len_all + 1);
		if (dst)
		{
			ft_strcat(ft_strcpy(dst, temp_s1), s2);
			return (dst);
		}
	}
	return (NULL);
}
