/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:38:17 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 19:04:17 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <limits.h>

char			valid_param_byte(unsigned char *param_byte,
														unsigned char opcode)
{
	t_op			*opcode_descr;
	int				decal;
	int				i;
	unsigned char	a;

	opcode_descr = get_opcode_descr_with_opcode(opcode);
	decal = 6;
	i = 0;
	while (i < opcode_descr->nb_params)
	{
		a = (*param_byte >> decal) % 4;
		if (a == REG_CODE)
			a = T_REG;
		else if (a == DIR_CODE)
			a = T_DIR;
		else if (a == IND_CODE)
			a = T_IND;
		if (!is_in_tab(a, opcode_descr->params_types, i))
			return (0);
		decal -= 2;
		i++;
	}
	return (1);
}

unsigned char	*next_instr(t_vm *vm, unsigned char *current_instr)
{
	if (current_instr < vm->memory + MEM_SIZE - 1)
		return (current_instr + 1);
	return (vm->memory);
}

int				get_length_of_type(t_op *opcode_descr, unsigned char type)
{
	if (type == DIR_CODE)
	{
		if (opcode_descr->small_dir)
			return (DIR_SIZE / 2);
		return (DIR_SIZE);
	}
	if (type == IND_CODE)
		return (IND_SIZE);
	else if (type == REG_CODE)
		return (REG_SIZE);
	return (0);
}

unsigned char	t_to_code(unsigned char t)
{
	if (t == T_REG)
		return (REG_CODE);
	if (t == T_IND)
		return (IND_CODE);
	return (DIR_CODE);
}

void			get_params_length(int *params_length, t_op *opcode_descr,
													unsigned char *param_byte)
{
	int		decal;
	int		i;

	if (!param_byte)
	{
		params_length[0] = get_length_of_type(opcode_descr,
									t_to_code(opcode_descr->params_types[0]));
	}
	else
	{
		decal = 6;
		i = 0;
		while (i < opcode_descr->nb_params)
		{
			params_length[i] = get_length_of_type(opcode_descr,
												(*param_byte >> decal) % 4);
			i++;
			decal -= 2;
		}
	}
}
