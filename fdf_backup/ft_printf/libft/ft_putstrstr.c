/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:17:33 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:17:34 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
