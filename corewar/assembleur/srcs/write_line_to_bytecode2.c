/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_line_to_bytecode2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:33:37 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/22 13:34:12 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_to_bytecode.h"

int				write_opcode(unsigned char opcode, t_list **bytes_end)
{
	t_list	*tmp;

	if (!(tmp = ft_lstnew(&opcode, sizeof(unsigned char))))
		return (0);
	ft_lstaddend(bytes_end, tmp);
	return (1);
}

t_op			*get_opcode_descr_with_opcode(int opcode)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (g_op_tab[i].opcode == opcode)
			return (&(g_op_tab[i]));
		i++;
	}
	return (NULL);
}

unsigned char	set_two_bits_from(unsigned char byte, unsigned char bits,
																	int from)
{
	from = 8 - from;
	byte = (byte | (bits << (from - 2)));
	return (byte);
}

unsigned char	get_param_byte(unsigned char param_byte, t_instruct *instruct,
																	int decal)
{
	if (instruct->type == REG)
		param_byte = set_two_bits_from(param_byte, REG_CODE, decal);
	else if (instruct->type == INDIR)
		param_byte = set_two_bits_from(param_byte, IND_CODE, decal);
	else if (instruct->type == DIRE)
		param_byte = set_two_bits_from(param_byte, DIR_CODE, decal);
	else
		return (big_error());
	return (param_byte);
}

int				write_param_byte_if_nec(t_instruct *instruct,
									t_list **bytes_end, t_function *function)
{
	t_list			*tmp;
	t_op			*opcode;
	unsigned char	param_byte;
	int				decal;

	if (!(opcode = get_opcode_descr_with_opcode(instruct->opcode)))
		return (big_error());
	if (!opcode->has_param_byte)
		return (1);
	param_byte = 0;
	decal = 0;
	instruct = instruct->next;
	while (instruct)
	{
		if (!(param_byte = get_param_byte(param_byte, instruct, decal)))
			return (0);
		decal += 2;
		instruct = instruct->next;
	}
	if (!(tmp = ft_lstnew(&param_byte, sizeof(unsigned char))))
		return (0);
	ft_lstaddend(bytes_end, tmp);
	function->bytes_written++;
	return (1);
}
