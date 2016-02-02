/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sixth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:40:28 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 18:56:24 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <limits.h>

int		add_lengths(int *params_length, int nb)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < nb)
	{
		len += params_length[i];
		i++;
	}
	return (len);
}

int		execute_param_byte(t_vm *vm, t_process *process)
{
	int				opcode;
	t_op			*opcode_descr;
	t_params		params;

	opcode = process->current_opcode;
	opcode_descr = get_opcode_descr_with_opcode(opcode);
	if (!(params.params = (int*)malloc(sizeof(int) * opcode_descr->nb_params)))
		return (1);
	if (!(params.params_length = (int*)malloc(sizeof(int) *
													opcode_descr->nb_params)))
		return (1);
	get_params_length(params.params_length, opcode_descr, next_instr(vm,
														process->next_instr));
	parse_params(vm, next_instr(vm, next_instr(vm, process->next_instr)),
											&params, opcode_descr->nb_params);
	return (opcode_descr->function(vm, process, params.params,
				add_lengths(params.params_length, opcode_descr->nb_params)));
}

int		execute_no_param_byte(t_vm *vm, t_process *process)
{
	int				opcode;
	t_op			*opcode_descr;
	int				*parametres;
	int				*params_length;
	t_params		params;

	opcode = process->current_opcode;
	opcode_descr = get_opcode_descr_with_opcode(opcode);
	if (!(parametres = (int*)malloc(sizeof(int) * opcode_descr->nb_params)))
		return (1);
	if (!(params_length = (int*)malloc(sizeof(int) * opcode_descr->nb_params)))
		return (1);
	params.params = parametres;
	params.params_length = params_length;
	get_params_length(params_length, opcode_descr, NULL);
	parse_params(vm, next_instr(vm, process->next_instr), &params,
													opcode_descr->nb_params);
	return (opcode_descr->function(vm, process, parametres,
						add_lengths(params_length, opcode_descr->nb_params)));
}

char	opcode_is_not_zjmp(char opcode)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (g_op_tab[i].opcode == opcode
			&& ft_strcmp("zjmp", g_op_tab[i].name) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	handle_invalid_param_byte(t_vm *vm, t_process *process,
														unsigned char *opcode)
{
	int				*params_length;
	t_op			*opcode_descr;

	opcode_descr = get_opcode_descr_with_opcode(*opcode);
	if (!(params_length = (int*)malloc(sizeof(int) * opcode_descr->nb_params)))
		return ;
	get_params_length(params_length, opcode_descr, next_instr(vm,
														process->next_instr));
	increment_next_instr(vm, process, add_lengths(params_length,
												opcode_descr->nb_params) + 2);
	process->remaining_cycles = get_cycles_for_opcode(*process->next_instr);
	process->current_opcode = *process->next_instr;
	if (process->remaining_cycles > 0)
		process->remaining_cycles--;
}
