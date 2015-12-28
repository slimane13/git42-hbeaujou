/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 16:22:20 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/28 15:33:00 by hbeaujou         ###   ########.fr       */
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
	int pointer_valueLargerThanMinWidth_zeroFlag;
	int test_simple_mix;

	str = (char *)malloc(sizeof(char) * 30);
	i = 2;
	pointer_valueLargerThanMinWidth_zeroFlag = 30;
	free = 1;
	test_simple_mix = 4;
	c = 'c';
//	printf("%d", printf("%s %d %p %x %S", "bonjour ", 42, &free, 42, L"لحم خنزير"));
//	printf("% Zoooo");
	printf("%.5p", 0);
	printf("\n");
//	printf("%d", ft_printf("%s %d %p %x %S", "bonjour ", 42, &free, 42, L"لحم خنزير"));
//	ft_printf("%d et %% et %s%o %c", 12, "LOL", 12, 'd');
	ft_printf("%.5p", 0);
	printf("\n");
	return (0);
}
