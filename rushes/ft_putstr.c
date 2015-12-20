/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:38:26 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:38:27 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (write(fd, "(null)", 6));
	while (s[i] != '\0')
		i++;
	return (write(fd, s, i));
}

ssize_t	ft_putstr(char const *s)
{
	return (ft_putstr_fd(s, 1));
}

ssize_t	ft_putendl_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (write(fd, "(null)", 6));
	while (s[i] != '\0')
		i++;
	write(fd, s, i);
	write(fd, "\n", 1);
	return (i + 1);
}

ssize_t	ft_putendl(char const *s)
{
	return (ft_putendl_fd(s, 1));
}
