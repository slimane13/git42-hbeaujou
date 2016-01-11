/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:10:31 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/07 21:31:59 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*temp_s;
	unsigned int	i;

	i = 0;
	if (s && len)
	{
		temp_s = ft_strnew(len);
		if (temp_s)
		{
			while (i++ < start)
				s++;
			strncpy(temp_s, s, len);
			return (temp_s);
		}
	}
	return (NULL);
}
