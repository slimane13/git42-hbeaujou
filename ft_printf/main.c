/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 16:22:20 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/28 11:09:25 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void test(wint_t c, int *b)
{
	if (c<0x80) *b++=c;
	else if (c<0x800) *b++=192+c/64, *b++=128+c%64;
	else if (c-0xd800u<0x800) {}
	else if (c<0x10000) *b++=224+c/4096, *b++=128+c/64%64, *b++=128+c%64;
	else if (c<0x110000) *b++=240+c/262144, *b++=128+c/4096%64, *b++=128+c/64%64, *b++=128+c%64;
	else return;
}

int main(void)
{
	int i;
	int d;
	char c;
	char b;
	char *str;
	int test_simple_mix;

	str = (char *)malloc(sizeof(char) * 30);
	i = 2;
	test_simple_mix = 4;
	//	printf("%d", printf("%S", L"我是一只猫。"));
	printf("%S, %lc", L"暖", L'ح');
	printf("\n");
	ft_printf("%S, %lc", L"暖", L'ح');
	//	printf("%d", ft_printf("%S", L"我是一只猫。"));
	printf("\n");
	return (0);
}
