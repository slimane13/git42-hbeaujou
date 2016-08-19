/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 13:07:00 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/08/19 13:24:16 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ft_malloc.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
