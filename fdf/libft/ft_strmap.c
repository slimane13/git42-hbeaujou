/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:16:27 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:16:29 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;
	unsigned int	len;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = ft_strnew(len);
	while (i < len)
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}
