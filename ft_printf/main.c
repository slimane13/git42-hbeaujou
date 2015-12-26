/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 16:22:20 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/26 18:23:33 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
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
	printf("%d", printf("% X|%+X", 42, 42));
	printf("\n");
	printf("%d", ft_printf("% X|%+X", 42, 42));
	printf("\n");
	return (0);
}
