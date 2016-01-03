/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:20:35 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:20:36 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		s1_i;
	int		s2_i;
	int		ori_i;

	if (*s2 == '\0')
		return ((char*)s1);
	s1_i = 0;
	while (s1[s1_i])
	{
		ori_i = s1_i;
		s2_i = 0;
		while (s1[s1_i] == s2[s2_i] && s1[s1_i])
		{
			s1_i++;
			s2_i++;
		}
		if (s2[s2_i] == '\0')
			return ((char*)s1 + ori_i);
		s1_i = ori_i;
		s1_i++;
	}
	return (NULL);
}
