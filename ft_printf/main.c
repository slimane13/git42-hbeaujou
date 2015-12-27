/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 16:22:20 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/27 18:43:31 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf.h"

int main(void)
{
	int i;
	int test_simple_mix;

	i = 2;
	test_simple_mix = 4;
//	ft_printf("s: %s, p: %p, d:%d\n", "a string", &test_simple_mix, 42);
//	printf("s: %s, p: %p, d:%d\n", "a string", &test_simple_mix, 42);
//	ft_printf("%ld\n", ((long)INT_MAX) + 1);
//	printf("%ld\n", ((long)INT_MAX) + 1);
	printf("%d", printf("%S", L"我是一只猫。"));
	printf("\n");
	printf("%d", ft_printf("%S", L"我是一只猫。"));
	printf("\n");
	wchar_t j = L'が';
	wprintf (L"This is the hiragana: %lc", j);
	printf("%C", j);
	return (0);
}
