/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirkovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 12:23:05 by skirkovs          #+#    #+#             */
/*   Updated: 2016/01/31 16:42:47 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_st(t_vm *vm, t_process *proc, int *params, int len)
{
	unsigned char	*addr;

	if (valid_reg(params[0]))
	{
		if (type_of_n_param(vm, proc, 1) == REG_CODE)
		{
			if (valid_reg(params[1]))
				proc->registres[params[1] - 1] = proc->registres[params[0] - 1];
		}
		else
		{
			addr = get_real_addr_of_ind(vm, proc->next_instr,
								(short)params[1], 1);
			copy_val_at(vm, addr,
					(unsigned int)proc->registres[params[0] - 1], 4);
		}
	}
	return (len);
}

int		op_sti(t_vm *vm, t_process *proc, int *params, int len)
{
	unsigned char	*addr;
	int				v1;
	int				v2;

	if (valid_reg(params[0]))
	{
		g_error = 0;
		v1 = get_val_of_n_param(vm, proc, params, 1);
		if (g_error)
			return (len);
		v2 = get_val_of_n_param(vm, proc, params, 2);
		if (g_error)
			return (len);
		addr = vm->memory + (((v1 + v2) % IDX_MOD) +
								(proc->next_instr - vm->memory)) % MEM_SIZE;
		copy_val_at(vm, addr, (unsigned int)proc->registres[params[0] - 1], 4);
	}
	return (len);
}
