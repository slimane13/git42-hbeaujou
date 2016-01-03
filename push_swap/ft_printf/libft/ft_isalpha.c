/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:13:43 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:13:44 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int		ft_isalpha_spec(int c)
{
	if (c == 'd' || c == 'i' || c == 'D' || c == 'u' || c == 'U' ||
			c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p' ||
			c == 'x' || c == 'X' || c == 'o' || c == 'O')
		return (1);
	return (0);
}

int		ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

void	cut_ntoa(char *res, int *limit)
{
	res[0] = '-';
	*limit = 1;
}
