/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltstr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:12:43 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/21 19:15:13 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	len_str(unsigned long long n, size_t base)
{
	int		cnt;

	cnt = 0;
	while (n / base)
	{
		n /= base;
		cnt++;
	}
	return (cnt);
}

void		ft_ulltstr_base(unsigned long long n, char *base_str, char *buf)
{
	size_t	base;
	int		size;

	if (n == 0)
	{
		buf[0] = '0';
		buf[1] = 0;
	}
	base = ft_strlen(base_str);
	size = len_str(n, base);
	buf[size + 1] = 0;
	while (n)
	{
		buf[size] = base_str[n % base];
		size--;
		n /= base;
	}
}
