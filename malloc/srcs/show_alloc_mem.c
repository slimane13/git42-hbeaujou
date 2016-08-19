/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 13:08:52 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/08/19 13:08:53 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

int				print_address(void *address)
{
	int			*int_mem;

	int_mem = (int *)address;
	address = address + 4;
	ft_putaddress(address);
	ft_putstr(" - ");
	ft_putaddress(address + (*int_mem));
	ft_putstr(" : ");
	ft_putnbr((*int_mem));
	ft_putstr(" octets\n");
	return (*int_mem);
}

void			put_type(char *type)
{
	if (*type == TINY)
		ft_putstr("TINY : ");
	else if (*type == SMALL)
		ft_putstr("SMALL : ");
	else if (*type == LARGE)
		ft_putstr("LARGE : ");
	if (*type == TINY || *type == SMALL || *type == LARGE)
	{
		ft_putaddress((void *)type);
		ft_putchar('\n');
	}
}

int				put_page(char *mem)
{
	int			i;
	int			total;
	int			*int_mem;
	int			*int_mem2;

	total = 0;
	put_type(mem);
	int_mem2 = (int *)(mem + 1);
	i = 13;
	while (i < get_max_type_size(*int_mem2))
	{
		int_mem = (int *)(mem + i);
		if (*int_mem == 0)
			break ;
		if (*int_mem != 0)
			total += print_address(mem + i);
		i += *int_mem;
		i += 4;
	}
	return (total);
}

void			show_alloc_mem(void)
{
	void		*mem;
	void		**ptr_mem;
	int			total;

	total = 0;
	mem = get_malloc(0, 0);
	while (mem)
	{
		total += put_page((char*)mem);
		ptr_mem = (void **)(mem + 5);
		mem = *ptr_mem;
	}
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putstr(" octets\n");
}
