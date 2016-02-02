/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:03:28 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 16:40:20 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_add(t_vm *vm, t_process *process, int *params, int len)
{
	(void)vm;
	if (valid_reg(params[0]) && valid_reg(params[1]) && valid_reg(params[2]))
	{
		process->registres[params[2] - 1] = process->registres[params[0] - 1]
											+ process->registres[params[1] - 1];
		if (process->registres[params[2] - 1] == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	return (len);
}

int		op_sub(t_vm *vm, t_process *process, int *params, int len)
{
	(void)vm;
	if (valid_reg(params[0]) && valid_reg(params[1]) && valid_reg(params[2]))
	{
		process->registres[params[2] - 1] = process->registres[params[0] - 1]
											- process->registres[params[1] - 1];
		if (process->registres[params[2] - 1] == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	return (len);
}

int		g_error;

int		get_val_of_n_param(t_vm *vm, t_process *process, int *params, int n)
{
	int				val;
	unsigned char	*addr;
	char			type;

	if ((type = type_of_n_param(vm, process, n)) == IND_CODE)
	{
		addr = vm->memory + ((((short)params[n]) % IDX_MOD)
							+ (process->next_instr - vm->memory)) % MEM_SIZE;
		val = get_val_at(vm, addr, 4);
	}
	else if (type == REG_CODE)
	{
		if (!valid_reg(params[n]))
		{
			g_error = 1;
			return (0);
		}
		val = process->registres[params[n] - 1];
	}
	else
		val = (short)params[n];
	return (val);
}

char	*print_val(int val, int is_reg)
{
	if (is_reg)
		return (ft_strjoin("r", ft_itoa(val)));
	return (ft_itoa(val));
}
