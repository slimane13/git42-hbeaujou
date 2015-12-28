/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 16:22:20 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/28 12:44:36 by hbeaujou         ###   ########.fr       */
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
//	printf("%d", printf("%s %C %d %p %x %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
	printf("{% S}", 0);
	printf("\n");
//	printf("%d", ft_printf("%s %C %d %p %x %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
	ft_printf("{% S}", 0);
	printf("\n");
	return (0);
}
