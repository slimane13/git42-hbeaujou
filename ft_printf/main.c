/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 16:22:20 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/28 14:21:24 by hbeaujou         ###   ########.fr       */
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
	printf("% Zoooo");
	printf("\n");
//	printf("%d", ft_printf("%s %C %d %p %x %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
//	ft_printf("%d et %% et %s%o %c", 12, "LOL", 12, 'd');
	ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
				L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
					L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	printf("\n");
	return (0);
}
