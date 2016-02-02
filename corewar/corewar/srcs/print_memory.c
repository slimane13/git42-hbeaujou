/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 10:03:29 by exam              #+#    #+#             */
/*   Updated: 2016/01/27 17:31:41 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hexa(unsigned char c)
{
	unsigned char	val1;
	unsigned char	val2;

	val1 = c / 16;
	val2 = c % 16;
	if (val1 > 9)
		val1 += -10 + 'a';
	else
		val1 += '0';
	if (val2 > 9)
		val2 += -10 + 'a';
	else
		val2 += '0';
	write(1, &val1, 1);
	write(1, &val2, 1);
}

void	print_chars_n_newline(unsigned char *addr1, size_t start,
												size_t end, size_t *printed)
{
	size_t	i;

	i = *printed;
	*printed = 0;
	while (i < 40)
	{
		write(1, " ", 1);
		i++;
	}
	while (start < end)
	{
		if (addr1[start] >= 32 && addr1[start] < 127)
			write(1, addr1 + start, 1);
		else
			write(1, ".", 1);
		start++;
	}
	write(1, "\n", 1);
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*addr1;
	size_t			i;
	size_t			printed;

	if (!addr)
		return ;
	addr1 = (unsigned char*)addr;
	i = 0;
	printed = 0;
	while (i < size)
	{
		print_hexa(addr1[i]);
		printed += 2;
		if (i % 2 == 1)
		{
			write(1, " ", 1);
			printed++;
		}
		i++;
		if (i % 16 == 0)
			print_chars_n_newline(addr1, i - 16, i, &printed);
	}
	if (i % 16 != 0)
		print_chars_n_newline(addr1, size - size % 16, i, &printed);
}
