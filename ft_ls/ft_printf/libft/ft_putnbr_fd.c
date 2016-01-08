/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:17:06 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:17:07 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			if (n > -10)
				ft_putchar_fd(-n + '0', fd);
			else
			{
				ft_putnbr_fd(-(n / 10), fd);
				ft_putchar_fd(-(n % 10) + '0', fd);
			}
		}
		else
		{
			if (n < 10)
				ft_putchar_fd(n + '0', fd);
			else
			{
				ft_putnbr_fd(n / 10, fd);
				ft_putchar_fd(n % 10 + '0', fd);
			}
		}
	}
}
