/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourth.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:34:39 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 15:36:47 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <limits.h>

void	go_to_next_byte(t_vm *vm, t_process *process)
{
	if (process->next_instr < vm->memory + MEM_SIZE - 1)
		process->next_instr++;
	else
		process->next_instr = vm->memory;
	process->remaining_cycles = get_cycles_for_opcode(*process->next_instr);
	process->current_opcode = *process->next_instr;
	if (process->remaining_cycles > 0)
		process->remaining_cycles--;
}

char	valid_opcode(unsigned char *opcode)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (*opcode == g_op_tab[i].opcode)
			return (1);
		i++;
	}
	return (0);
}

char	opcode_has_param_byte(unsigned char opcode)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (g_op_tab[i].opcode == opcode)
			return (g_op_tab[i].has_param_byte);
		i++;
	}
	ft_putendl_fd("BIG ERROR !", 2);
	return (0);
}

t_op	*get_opcode_descr_with_opcode(unsigned char opcode)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (g_op_tab[i].opcode == opcode)
			return (&g_op_tab[i]);
		i++;
	}
	ft_putendl_fd("BIG ERROR !", 2);
	return (NULL);
}

int		is_in_tab(int a, int *tab, int i)
{
	if (tab[i] & a)
		return (1);
	return (0);
}
