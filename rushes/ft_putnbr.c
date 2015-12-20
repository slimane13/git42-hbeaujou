/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:37:55 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:37:56 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base_fd(long int n, int base, int fd)
{
	long int	div;
	char		temp;

	if (base != 10)
		n = (unsigned long int)n;
	div = 1;
	if (n < 0)
		write(fd, "-", 1);
	if (n < 0)
		n = -n;
	while (n / div >= base)
		div *= base;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			temp += 39;
			write(fd, &temp, 1);
		}
		else
			write(fd, &temp, 1);
		n %= div;
		div /= base;
	}
}

void	ft_putnbr_base(long int n, int base)
{
	ft_putnbr_base_fd(n, base, 1);
}

void	ft_putnbr_fd(long int n, int fd)
{
	ft_putnbr_base_fd(n, 10, fd);
}

void	ft_putnbr(long int n)
{
	ft_putnbr_base_fd(n, 10, 1);
}
