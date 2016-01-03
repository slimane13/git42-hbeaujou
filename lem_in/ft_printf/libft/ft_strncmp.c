/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:19:44 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:19:45 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((int)n == 0)
		return (0);
	return ((*s1 == *s2 && *s1 && n > 1) ?
			ft_strncmp(s1 + 1, s2 + 1, n - 1)
			: (unsigned char)*s1 - (unsigned char)*s2);
}
