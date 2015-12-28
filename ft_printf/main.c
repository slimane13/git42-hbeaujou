/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 16:22:20 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/28 15:15:19 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int i;
	int d;
	char c;
	char b;
	int free;
	char *str;
	int test_simple_mix;

	str = (char *)malloc(sizeof(char) * 30);
	i = 2;
	free = 1;
	test_simple_mix = 4;
	c = 'c';
//	printf("%d", printf("%s %d %p %x %S", "bonjour ", 42, &free, 42, L"لحم خنزير"));
//	printf("% Zoooo");
	printf("%d\n", printf("%hhS, %hhS", 0, L"米米"));
	printf("\n");
//	printf("%d", ft_printf("%s %d %p %x %S", "bonjour ", 42, &free, 42, L"لحم خنزير"));
//	ft_printf("%d et %% et %s%o %c", 12, "LOL", 12, 'd');
	printf("%d\n", ft_printf("%hhS, %hhS", 0, L"米米"));
	printf("\n");
	return (0);
}
