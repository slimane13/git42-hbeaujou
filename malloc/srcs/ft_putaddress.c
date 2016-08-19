/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 13:07:48 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/08/19 13:07:49 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

void						ft_putaddress(void *ptr)
{
	unsigned long long		llu_ptr;
	static char				hexa_tab[] = "0123456789ABCDEF";
	static char				hexa[10];
	int						i;

	llu_ptr = (unsigned long long)ptr;
	ft_bzero(hexa, 10);
	i = 8;
	while (llu_ptr)
	{
		hexa[i] = hexa_tab[llu_ptr % 16];
		llu_ptr = llu_ptr / 16;
		i--;
	}
	ft_putstr("0x");
	ft_putstr(hexa);
}
