/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:03:28 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 16:42:55 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_and_or_xor(t_vm *vm, t_process *process, int *params, char sign)
{
	int				val1;
	int				val2;

	g_error = 0;
	if (!valid_reg(params[2]))
		return (0);
	val1 = get_val_of_n_param(vm, process, params, 0);
	if (g_error)
		return (0);
	val2 = get_val_of_n_param(vm, process, params, 1);
	if (g_error)
		return (0);
	if (sign == '&')
		process->registres[params[2] - 1] = val1 & val2;
	else if (sign == '|')
		process->registres[params[2] - 1] = val1 | val2;
	else if (sign == '^')
		process->registres[params[2] - 1] = val1 ^ val2;
	return (!(process->carry = process->registres[params[2] - 1] == 0) + 1);
}

int		op_and(t_vm *vm, t_process *process, int *params, int len)
{
	op_and_or_xor(vm, process, params, '&');
	return (len);
}

int		op_or(t_vm *vm, t_process *process, int *params, int len)
{
	op_and_or_xor(vm, process, params, '|');
	return (len);
}

int		op_xor(t_vm *vm, t_process *process, int *params, int len)
{
	op_and_or_xor(vm, process, params, '^');
	return (len);
}
