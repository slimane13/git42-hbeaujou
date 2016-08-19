/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 13:08:46 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/08/19 13:08:47 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

char		get_type(size_t size)
{
	if (size <= TINYSIZE)
		return (TINY);
	else if (size <= SMALLSIZE)
		return (SMALL);
	else
		return (LARGE);
}

int			get_size(size_t size)
{
	if (size <= TINYSIZE)
		return (TINYSIZE);
	else if (size <= SMALLSIZE)
		return (SMALLSIZE);
	else
		return (size);
}

int			get_max_type_size(size_t size)
{
	if (size <= TINYSIZE)
		return (TINYMAX);
	else if (size <= SMALLSIZE)
		return (SMALLMAX);
	else
		return (size + 17);
}
