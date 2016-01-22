/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_line_to_bytecode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:31:58 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/21 17:07:18 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_to_bytecode.h"

void		add_to_labels_to_resolve1(t_instruct *instruct,
		t_function *function, int bytes_written_before, t_op *opcode, t_bytes_n_labels *bytes_n_labels)
{
	unsigned int	val_val;
	unsigned char	*val;
	t_list			*tmp;

	val_val = 1;
	val = (unsigned char*)&val_val;
	tmp = ft_lstnew(val, IND_SIZE);
	ft_lstaddend(&(bytes_n_labels->bytes_end), tmp);
	ft_lstaddend(&(bytes_n_labels->labels_to_resolve_end), ft_lstnew(new_resolve(instruct->name + 1, function, bytes_written_before, bytes_n_labels->bytes_end), sizeof(t_to_resolve)));
	if (!bytes_n_labels->labels_to_resolve)
		bytes_n_labels->labels_to_resolve = bytes_n_labels->labels_to_resolve_end;
	((t_to_resolve*)(bytes_n_labels->labels_to_resolve_end)->content)->small_dir = opcode->small_dir;
	((t_to_resolve*)(bytes_n_labels->labels_to_resolve_end)->content)->opcode = opcode->opcode;
	((t_to_resolve*)(bytes_n_labels->labels_to_resolve_end)->content)->has_param_byte = opcode->has_param_byte;
}

int			write_params(t_instruct *instruct, t_function *function,
						t_function *functions, t_bytes_n_labels *bytes_n_labels)
{
	t_list			*tmp;
	unsigned int	val_val;
	unsigned char	*val;
	t_op			*opcode;
	int				bytes_written_before;

	bytes_written_before = function->bytes_written;
	if (!(opcode = get_opcode_descr_with_opcode(instruct->opcode)))
		return (big_error());
	val = NULL;
	instruct = instruct->next;
	while (instruct)
	{
		if (instruct->type == INDIR)
		{
			if (instruct->name[0] == LABEL_CHAR)
				add_to_labels_to_resolve1(instruct, function, bytes_written_before, opcode, bytes_n_labels);
			else
			{
				val_val = ft_atoi(instruct->name);
				val = (unsigned char*)&val_val;
				tmp = ft_lstnew(val, IND_SIZE);
				ft_lstaddend(&(bytes_n_labels->bytes_end), tmp);
			}
			function->bytes_written += IND_SIZE;
		}
		else if (instruct->type == REG)
		{
			val_val = ft_atoi(instruct->name + 1);
			val = (unsigned char*)&val_val;
			tmp = ft_lstnew(val, REG_SIZE);
			ft_lstaddend(&(bytes_n_labels->bytes_end), tmp);
			function->bytes_written += REG_SIZE;
		}
		else if (instruct->type == DIRE)
		{
			if (instruct->name[1] == LABEL_CHAR)
			{
				val_val = 1;
				val = (unsigned char*)&val_val;
				tmp = ft_lstnew(val, opcode->small_dir ? DIR_SIZE / 2 : DIR_SIZE);
				ft_lstaddend(&(bytes_n_labels->bytes_end), tmp);
				tmp = ft_lstnew(new_resolve(instruct->name + 2, function, bytes_written_before, bytes_n_labels->bytes_end), sizeof(t_to_resolve));
				ft_lstaddend(&(bytes_n_labels->labels_to_resolve_end), tmp);
				if (!bytes_n_labels->labels_to_resolve)
					bytes_n_labels->labels_to_resolve = bytes_n_labels->labels_to_resolve_end;
				((t_to_resolve*)(bytes_n_labels->labels_to_resolve_end)->content)->small_dir = opcode->small_dir;
				((t_to_resolve*)(bytes_n_labels->labels_to_resolve_end)->content)->opcode = opcode->opcode;
				((t_to_resolve*)(bytes_n_labels->labels_to_resolve_end)->content)->has_param_byte = opcode->has_param_byte;
			}
			else
			{
				val_val = ft_atoi(instruct->name + 1);
				val = (unsigned char*)&val_val;
				tmp = ft_lstnew(val, opcode->small_dir ? DIR_SIZE / 2 : DIR_SIZE);
				ft_lstaddend(&(bytes_n_labels->bytes_end), tmp);
			}
			function->bytes_written += opcode->small_dir ? DIR_SIZE / 2 : DIR_SIZE;
		}
		else
			return (0);
		instruct = instruct->next;
	}
	return (1);
}

int			write_opcode(unsigned char opcode, t_list **bytes_end)
{
	t_list	*tmp;

	if (!(tmp = ft_lstnew(&opcode, sizeof(unsigned char))))
		return (0);
	ft_lstaddend(bytes_end, tmp);
	return (1);
}

t_op		*get_opcode_descr_with_opcode(int opcode)
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

unsigned char	set_two_bits_from(unsigned char byte, unsigned char bits, int from)
{
	from = 8 - from;
	byte = (byte | (bits<<(from - 2)));
	return (byte);
}

int			write_param_byte_if_nec(t_instruct *instruct, t_list **bytes_end,
														t_function *function)
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
		if (instruct->type == REG)
			param_byte = set_two_bits_from(param_byte, REG_CODE, decal);
		else if (instruct->type == INDIR)
			param_byte = set_two_bits_from(param_byte, IND_CODE, decal);
		else if (instruct->type == DIRE)
			param_byte = set_two_bits_from(param_byte, DIR_CODE, decal);
		else
			return (big_error());
		decal += 2;
		instruct = instruct->next;
	}
	if (!(tmp = ft_lstnew(&param_byte, sizeof(unsigned char))))
		return (0);
	ft_lstaddend(bytes_end, tmp);
	function->bytes_written++;
	return (1);
}
