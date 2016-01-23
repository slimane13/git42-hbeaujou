/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_line_to_bytecode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:31:58 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/22 13:46:03 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_to_bytecode.h"

void			add_to_labels_to_resolve2(t_instruct *instruct,
				t_function *function, int bytes_written_before,
											t_bytes_n_labels *bytes_n_labels)
{
	unsigned int	val_val;
	unsigned char	*val;
	t_list			*tmp;
	t_op			*opcode;

	opcode = get_opcode_descr_with_opcode(instruct->opcode);
	val_val = 1;
	val = (unsigned char*)&val_val;
	tmp = ft_lstnew(val, opcode->small_dir ? DIR_SIZE / 2 : DIR_SIZE);
	ft_lstaddend(&(bytes_n_labels->bytes_end), tmp);
	tmp = ft_lstnew(new_resolve(instruct->name + 2, function,
		bytes_written_before, bytes_n_labels->bytes_end), sizeof(t_to_resolve));
	ft_lstaddend(&(bytes_n_labels->labels_to_resolve_end), tmp);
	if (!bytes_n_labels->labels_to_resolve)
		bytes_n_labels->labels_to_resolve =
										bytes_n_labels->labels_to_resolve_end;
	((t_to_resolve*)(bytes_n_labels->labels_to_resolve_end)->
										content)->small_dir = opcode->small_dir;
	((t_to_resolve*)(bytes_n_labels->labels_to_resolve_end)->
											content)->opcode = opcode->opcode;
	((t_to_resolve*)(bytes_n_labels->labels_to_resolve_end)->
							content)->has_param_byte = opcode->has_param_byte;
}

void			handle_indir(t_instruct *instruct, t_function **function,
					int bytes_written_before, t_bytes_n_labels *bytes_n_labels)
{
	unsigned int	val_val;
	unsigned char	*val;
	t_list			*tmp;

	if (instruct->name[0] == LABEL_CHAR)
		add_to_labels_to_resolve1(instruct, *function,
										bytes_written_before, bytes_n_labels);
	else
	{
		val_val = ft_atoi(instruct->name);
		val = (unsigned char*)&val_val;
		tmp = ft_lstnew(val, IND_SIZE);
		ft_lstaddend(&(bytes_n_labels->bytes_end), tmp);
	}
	(*function)->bytes_written += IND_SIZE;
}

void			handle_reg(t_instruct *instruct, t_function **function,
											t_bytes_n_labels *bytes_n_labels)
{
	unsigned int	val_val;
	unsigned char	*val;
	t_list			*tmp;

	val_val = ft_atoi(instruct->name + 1);
	val = (unsigned char*)&val_val;
	tmp = ft_lstnew(val, REG_SIZE);
	ft_lstaddend(&(bytes_n_labels->bytes_end), tmp);
	(*function)->bytes_written += REG_SIZE;
}

void			handle_dir(t_instruct *instruct, t_function **function,
					int bytes_written_before, t_bytes_n_labels *bytes_n_labels)
{
	unsigned int	val_val;
	unsigned char	*val;
	t_list			*tmp;
	t_op			*opcode;

	opcode = get_opcode_descr_with_opcode(instruct->opcode);
	if (instruct->name[1] == LABEL_CHAR)
		add_to_labels_to_resolve2(instruct, *function,
										bytes_written_before, bytes_n_labels);
	else
	{
		val_val = ft_atoi(instruct->name + 1);
		val = (unsigned char*)&val_val;
		tmp = ft_lstnew(val, opcode->small_dir ? DIR_SIZE / 2 : DIR_SIZE);
		ft_lstaddend(&(bytes_n_labels->bytes_end), tmp);
	}
	(*function)->bytes_written += opcode->small_dir ? DIR_SIZE / 2 : DIR_SIZE;
}

int				write_params(t_instruct *instruct, t_function *function,
						t_function *functions, t_bytes_n_labels *bytes_n_labels)
{
	t_op			*opcode;
	int				bytes_written_before;

	(void)functions;
	bytes_written_before = function->bytes_written;
	if (!(opcode = get_opcode_descr_with_opcode(instruct->opcode)))
		return (big_error());
	instruct = instruct->next;
	while (instruct)
	{
		instruct->opcode = opcode->opcode;
		if (instruct->type == INDIR)
			handle_indir(instruct, &function, bytes_written_before,
																bytes_n_labels);
		else if (instruct->type == REG)
			handle_reg(instruct, &function, bytes_n_labels);
		else if (instruct->type == DIRE)
			handle_dir(instruct, &function, bytes_written_before,
																bytes_n_labels);
		else
			return (0);
		instruct = instruct->next;
	}
	return (1);
}
