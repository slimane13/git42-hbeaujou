/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 02:45:59 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/27 02:46:03 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(s2);
	if (len == 0)
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		while (s2[j] == s1[i + j])
		{
			if (j == len - 1)
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
