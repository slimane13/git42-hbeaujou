/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:00:17 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/02 12:04:28 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdodo.h"

void	ft_putstrstr(char **strstr)
{
	int		i;

	i = 0;
	while (strstr[i])
	{
		ft_putendl(strstr[i]);
		i++;
	}
}
