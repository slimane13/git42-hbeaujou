/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:06:26 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/15 06:48:26 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
	{
		if (s1 != s2)
			return (0);
		return (1);
	}
	while (s1[i] && s2[i] && i < n)
	{
		if ((s1[i] - s2[i]))
			return (0);
		i++;
	}
	return (1);
}
