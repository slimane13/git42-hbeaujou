/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeabsolute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 06:05:50 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/01 06:05:52 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_makeabsolute(char *dir, char *file)
{
	char	*dst;

	dst = ft_strjoin(dir, file);
	return (dst);
}
