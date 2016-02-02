/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seventh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:42:49 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 16:31:24 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <limits.h>

void	execute_instruction(t_vm *vm, t_process *process)
{
	unsigned char	*opcode;
	int				len;
	char			is_not_zjmp;

	opcode = &process->current_opcode;
	is_not_zjmp = opcode_is_not_zjmp(process->current_opcode);
	if (opcode_has_param_byte(process->current_opcode))
	{
		if (!valid_param_byte(next_instr(vm, process->next_instr), *opcode))
			return (handle_invalid_param_byte(vm, process, opcode));
		len = execute_param_byte(vm, process);
		if (is_not_zjmp || len != 0)
			increment_next_instr(vm, process, len + 2);
	}
	else
	{
		len = execute_no_param_byte(vm, process);
		if (is_not_zjmp || len != 0)
			increment_next_instr(vm, process, len + 1);
	}
	process->remaining_cycles = get_cycles_for_opcode(*process->next_instr);
	process->current_opcode = *process->next_instr;
	if (process->remaining_cycles > 0)
		process->remaining_cycles--;
}

void	update_instructions(t_vm *vm)
{
	t_list		*tmp;
	t_process	*process;

	tmp = vm->processes;
	while (tmp)
	{
		process = ((t_process*)tmp->content);
		if ((valid_opcode(&process->current_opcode)
			&& get_cycles_for_opcode(process->current_opcode) ==
			process->remaining_cycles + 1 && valid_opcode(process->next_instr))
			|| (process->remaining_cycles == 0
				&& !valid_opcode(&process->current_opcode)))
		{
			process->current_opcode = *process->next_instr;
			process->remaining_cycles =
									get_cycles_for_opcode(*process->next_instr);
			if (process->remaining_cycles > 0)
				process->remaining_cycles--;
		}
		tmp = tmp->next;
	}
}

void	execute_processes(t_vm *vm)
{
	t_list		*tmp;

	tmp = vm->processes;
	while (tmp)
	{
		if (!valid_opcode(&((t_process*)tmp->content)->current_opcode))
			go_to_next_byte(vm, ((t_process*)tmp->content));
		else if (((t_process*)tmp->content)->remaining_cycles == 0)
			execute_instruction(vm, ((t_process*)tmp->content));
		else
			((t_process*)tmp->content)->remaining_cycles--;
		tmp = tmp->next;
	}
	update_instructions(vm);
}

void	decrement_cycle_to_die(int *cycle_to_die, int *to_die_iter, int *checks)
{
	*cycle_to_die -= CYCLE_DELTA;
	*to_die_iter -= CYCLE_DELTA;
	if (PRINT_INSTR)
		ft_printf("Cycle to die is now %d\n", *cycle_to_die);
	*checks = MAX_CHECKS;
}

void	init_vars(int *cycle_to_die, int *to_die_iter, int *checks)
{
	*cycle_to_die = CYCLE_TO_DIE;
	*to_die_iter = *cycle_to_die;
	*checks = MAX_CHECKS;
}
