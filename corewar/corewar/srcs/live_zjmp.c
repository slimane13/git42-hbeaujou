/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:03:28 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 18:11:39 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_player	*valid_player(t_vm *vm, int dir_val)
{
	int		i;

	i = 0;
	while (i < vm->nb_players)
	{
		if (dir_val == vm->players[i]->number)
			return (vm->players[i]);
		i++;
	}
	return (NULL);
}

int			type_of_n_param(t_vm *vm, t_process *process, int n)
{
	unsigned char	type;

	type = (*next_instr(vm, process->next_instr) >> (6 - (n * 2))) & 3;
	return (type);
}

int			get_modulo_even_neg(int val)
{
	if (val >= 0)
		return (val % IDX_MOD);
	return (-(-val % IDX_MOD));
}

int			op_live(t_vm *vm, t_process *process, int *params, int len)
{
	int			dir_val;
	t_player	*play;

	dir_val = params[0];
	process->last_live = vm->current_cycle;
	process->nb_live++;
	if ((play = valid_player(vm, dir_val)))
	{
		vm->last_player = dir_val;
		ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
														dir_val, play->name);
	}
	return (len);
}

int			op_zjmp(t_vm *vm, t_process *process, int *params, int len)
{
	if (process->carry == 1)
	{
		process->next_instr = get_real_addr_of_ind(vm, process->next_instr,
														(short)params[0], 1);
		process->remaining_cycles = get_cycles_for_opcode(*process->next_instr);
		process->current_opcode = *process->next_instr;
		if (process->remaining_cycles > 0)
			process->remaining_cycles--;
		return (0);
	}
	return (len);
}
