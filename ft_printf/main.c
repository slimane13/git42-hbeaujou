/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 16:22:20 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/28 14:39:58 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	c = 'c';
//	printf("%d", printf("%s %C %d %p %x %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
//	printf("% Zoooo");
	printf("{% S}", NULL);
	printf("\n");
//	printf("%d", ft_printf("%s %C %d %p %x %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
//	ft_printf("%d et %% et %s%o %c", 12, "LOL", 12, 'd');
	ft_printf("{% S}", NULL);
	printf("\n");
	return (0);
}
