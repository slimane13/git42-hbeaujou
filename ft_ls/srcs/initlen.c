/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:00:47 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/29 17:04:21 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_len	ft_initlen(void)
{
	t_len	len;

	len.links = 0;
	len.uid = 0;
	len.gid = 0;
	len.size = 0;
	len.major = 0;
	len.minor = 0;
	len.maj_min = 0;
	len.dev = 0;
	len.total_blocks = 0;
	len.nb_files = 0;
	return (len);
}
