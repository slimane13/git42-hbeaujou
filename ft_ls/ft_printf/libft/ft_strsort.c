/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 09:29:32 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/12 09:29:48 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsort(char *str)
{
	int		save_i;
	int		i;

	save_i = 0;
	if (str)
	{
		while (str[save_i])
		{
			i = save_i + 1;
			while (str[i])
			{
				if (str[i] < str[save_i])
					ft_swap(&str[save_i], &str[i]);
				i++;
			}
			save_i++;
		}
	}
}
