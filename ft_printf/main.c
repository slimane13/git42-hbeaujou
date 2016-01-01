/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 16:22:20 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 15:59:43 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

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
	int x = 1;
//	printf("%d", printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
//	printf("%d", ft_printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
	printf("%zhd\n", 4294967296);
	printf("\n");
	ft_printf("%zhd\n", 4294967296);
	return (0);
}
