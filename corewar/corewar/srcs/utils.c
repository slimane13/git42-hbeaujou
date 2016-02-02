/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:03:28 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 15:56:10 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned char	*get_real_addr_of_ind(t_vm *vm, unsigned char *ori_addr,
														int to_add, char modulo)
{
	unsigned char	*addr;

	if (modulo)
		addr = ori_addr + get_modulo_even_neg(to_add);
	else
		addr = ori_addr + to_add;
	if (addr >= vm->memory + MEM_SIZE)
		addr = vm->memory + (addr - (vm->memory + MEM_SIZE));
	else if (addr < vm->memory)
		addr = vm->memory + MEM_SIZE - (vm->memory - addr);
	return (addr);
}

unsigned int	get_val_at(t_vm *vm, unsigned char *addr, int nb)
{
	int				pow;
	int				i;
	unsigned int	res;

	i = 0;
	res = 0;
	pow = nb - 1;
	while (pow >= 0)
	{
		res += *(next_byte_nb(vm, addr, i)) * ft_pow(256, pow);
		i++;
		pow--;
	}
	return (res);
}

void			copy_val_at(t_vm *vm, unsigned char *addr,
										unsigned int val, int nb)
{
	int		i;
	char	bytes[4];
	int		j;

	*(int *)bytes = val;
	i = 0;
	j = 4;
	while (i < nb)
	{
		*addr = bytes[--j];
		addr++;
		if (addr - vm->memory >= MEM_SIZE)
			addr = vm->memory + (addr - vm->memory) % MEM_SIZE;
		i++;
	}
}

char			*get_name_of_opcode(char opcode)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (g_op_tab[i].opcode == opcode)
			return (g_op_tab[i].name);
		i++;
	}
	ft_putendl_fd("BIG ERROR\n", 2);
	return ("");
}

char			valid_reg(int param)
{
	if (param > 0 && param <= 16)
		return (1);
	return (0);
}
