/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:16:52 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:16:53 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	unsigned int	len;
	unsigned int	index;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (ft_strdup(s));
	i = 0;
	index = 0;
	len = ft_strlen(s);
	str = ft_strnew(len);
	while (i < len)
	{
		str[i] = (*f)(index, s[i]);
		i++;
		index++;
	}
	return (str);
}
