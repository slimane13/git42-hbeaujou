/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:53:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/31 16:37:29 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				ft_pow(int nb, int pui)
{
	int		res;

	res = 1;
	while (pui > 0)
	{
		res = nb * res;
		pui--;
	}
	return (res);
}

static void		init_magic(t_magic *magic)
{
	magic->k = 0;
	magic->m = 0;
	magic->j = -1;
	magic->i = 0;
	magic->total = 0;
}

void			parse_params2(unsigned char *str, int *to_read,
											unsigned int *final)
{
	t_magic			magic;

	init_magic(&magic);
	while (to_read[magic.i])
	{
		magic.total += to_read[magic.i];
		magic.i++;
	}
	magic.total--;
	while (to_read[++magic.j])
	{
		magic.m = to_read[magic.j];
		magic.res = 0;
		magic.k = 0;
		while (magic.m > 0)
		{
			magic.res += (unsigned char)str[magic.total]
				* ft_pow(256, magic.k);
			magic.total--;
			magic.m--;
			magic.k++;
		}
		final[magic.j] = magic.res;
	}
}

unsigned char	*next_byte_nb(t_vm *vm, unsigned char *byte, int nb)
{
	while (nb > 0)
	{
		if (byte < vm->memory + MEM_SIZE - 1)
			byte++;
		else
			byte = vm->memory;
		nb--;
	}
	return (byte);
}

void			parse_params(t_vm *vm, unsigned char *str,
							t_params *params, int nb)
{
	int				i;
	int				pow;
	int				res;

	i = 0;
	while (i < nb)
	{
		pow = params->params_length[i] - 1;
		res = 0;
		while (pow >= 0)
		{
			res += *(unsigned char*)next_byte_nb(vm, str,
						params->params_length[i] - 1 - pow) * ft_pow(256, pow);
			pow--;
		}
		str = next_byte_nb(vm, str, params->params_length[i]);
		params->params[i] = res;
		i++;
	}
}
