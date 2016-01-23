/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_line_to_bytecode3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:39:36 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/22 13:41:37 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_to_bytecode.h"

int				label_not_found(char *label)
{
	ft_putstr_fd("LABEL NOT FOUND : ", 2);
	ft_putendl_fd(label, 2);
	return (0);
}

void			add_to_labels_to_resolve1(t_instruct *instruct,
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
	tmp = ft_lstnew(val, IND_SIZE);
	ft_lstaddend(&(bytes_n_labels->bytes_end), tmp);
	ft_lstaddend(&(bytes_n_labels->labels_to_resolve_end),
			ft_lstnew(new_resolve(instruct->name + 1, function,
	bytes_written_before, bytes_n_labels->bytes_end), sizeof(t_to_resolve)));
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
