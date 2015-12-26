/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:01:50 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/21 19:22:17 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int n)
{
	if (n < 0)
		n = -n;
	if (n < 10)
		return (1);
	else
		return (1 + ft_nbrlen(n / 10));
	return (0);
}

int	ft_nbrlen_ll(long long n)
{
	if (n < 0)
		n = -n;
	if (n < 10)
		return (1);
	else
		return (1 + ft_nbrlen_ll(n / 10));
	return (0);
}
