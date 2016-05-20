/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:09:29 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:09:33 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t n)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char *) * n);
	tmp = ft_strncpy(tmp, src, n);
	dst = (void *)ft_strncpy(dst, tmp, n);
	free(tmp);
	return (dst);
}
