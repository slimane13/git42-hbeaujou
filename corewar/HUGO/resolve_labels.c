/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:34:18 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/21 13:52:58 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_to_bytecode.h"

unsigned long long	get_relative_addr_of_label(char *label, t_function *function,
										t_function *functions, t_op *opcode)
{
	unsigned long long	res;
	unsigned int		bytes_written;
	int					found;

	found = 0;
	res = 0;
	bytes_written = 0;
	return (1);
	while (functions)
	{
		if (ft_strcmp(functions->label, label) == 0)
			found = 1;
		if (found)
			bytes_written += functions->bytes_written;
		if (functions == function)
		{
			if (bytes_written > 0 && opcode->has_param_byte)
			{
				if (opcode->small_dir)
					return (res - bytes_written + 2);
				return (res - bytes_written + 3);
			}
			return (res - bytes_written + 1);
		}
		functions = functions->next;
	}
	return (res);
}

int			label_not_found(char *label)
{
	ft_putstr_fd("LABEL NOT FOUND : ", 2);
	ft_putendl_fd(label, 2);
	return (0);
}

t_to_resolve	*new_resolve(char *label, t_function *function_from,
							int bytes_written_from, t_list *byte_to_override)
{
	t_to_resolve	*res;
	if (!(res = (t_to_resolve*)malloc(sizeof(t_to_resolve))))
		return (NULL);
	res->label_to_seek = ft_strdup(label);
	res->function_from = function_from;
	res->bytes_written_in_function_from = bytes_written_from;
	res->byte_to_override = byte_to_override;
	return (res);
}

void		replace_bytes(t_list *bytes, void *val, size_t size)
{
	void	*res;

	res = malloc(size);
	ft_memcpy(res, val, size);
	bytes->content = res;
	bytes->content_size = size;
}

int			resolve_unresolved_labels(t_list *labels_to_resolve)
{
	t_function		*tmp_function;
	t_to_resolve	*to_res;
	unsigned int	bytes_inbetween;
	char			done;

	while (labels_to_resolve)
	{
		done = 0;
		to_res = ((t_to_resolve*)labels_to_resolve->content);
		bytes_inbetween = to_res->function_from->bytes_written - to_res->bytes_written_in_function_from + 1;
		tmp_function = to_res->function_from->next;
		while (tmp_function && !done)
		{
			if (ft_strcmp(to_res->label_to_seek, tmp_function->label) == 0)
			{
				if (to_res->has_param_byte)
					bytes_inbetween += 1;
				replace_bytes(to_res->byte_to_override, &bytes_inbetween, to_res->byte_to_override->content_size);
				done = 1;
			}
			bytes_inbetween += tmp_function->bytes_written;
			tmp_function = tmp_function->next;
		}
		if (!done)
		{
			bytes_inbetween = 0;
			tmp_function = to_res->function_from;
			while (tmp_function && !done)
			{
				if (tmp_function == to_res->function_from)
					bytes_inbetween += to_res->bytes_written_in_function_from;
				else
					bytes_inbetween += tmp_function->bytes_written;
				if (ft_strcmp(to_res->label_to_seek, tmp_function->label) == 0)
				{
					bytes_inbetween = 0 - bytes_inbetween + 1;
					if (to_res->has_param_byte)
						bytes_inbetween += 1;
					replace_bytes(to_res->byte_to_override, &bytes_inbetween, to_res->byte_to_override->content_size);
					done = 1;
				}
				tmp_function = tmp_function->prev;
			}
		}
		if (!done)
			return (label_not_found(to_res->label_to_seek));
		labels_to_resolve = labels_to_resolve->next;
	}
	return (1);
}
