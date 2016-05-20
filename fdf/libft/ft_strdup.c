/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:14:38 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:14:38 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char *s2;

	s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	return (ft_strcpy(s2, s1));
}
