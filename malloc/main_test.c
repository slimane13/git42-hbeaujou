/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 12:15:02 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/08/18 12:15:11 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_malloc.h>

void			test()
{
	size_t			i;
	char		*str;

	i = 0;
	str = NULL;
	while (i < 1000)
	{
		str = malloc(i * 10);
		str = realloc(str, i * 20);
		i++;
	}
	show_alloc_mem();
}

int				main(void)
{
	test();
	return (0);
}
