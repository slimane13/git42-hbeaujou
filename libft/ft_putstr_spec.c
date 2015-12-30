/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 14:23:23 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 14:23:46 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_spec(const char *s)
{
	if (s != NULL)
		write(1, s, ft_strlen(s));
	ft_putchar(0);
}
