/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:19:12 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:19:13 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	unsigned int	i;
	char			ch;

	i = ft_strlen(s);
	ch = c;
	while (s[i] != ch)
	{
		if (s[i] == s[0])
			return (0);
		i--;
	}
	return ((char *)s + i);
}
