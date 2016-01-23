/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:34:18 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/22 13:45:22 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_to_bytecode.h"

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

void			replace_bytes(t_list *bytes, void *val, size_t size)
{
	void	*res;

	res = malloc(size);
	ft_memcpy(res, val, size);
	bytes->content = res;
	bytes->content_size = size;
}

int				resolve_unresolved_labels_bef(t_to_resolve *to_res)
{
	t_function		*tmp_function;
	unsigned int	bytes_inbetween;
	char			done;

	done = 0;
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
			replace_bytes(to_res->byte_to_override, &bytes_inbetween,
									to_res->byte_to_override->content_size);
			done = 1;
		}
		tmp_function = tmp_function->prev;
	}
	return (!done ? 0 : 1);
}

int				resolve_unresolved_labels_after(t_list *labels_to_resolve,
														t_to_resolve *to_res)
{
	t_function		*tmp_function;
	unsigned int	bytes_inbetween;
	char			done;

	(void)labels_to_resolve;
	done = 0;
	bytes_inbetween = to_res->function_from->bytes_written
								- to_res->bytes_written_in_function_from + 1;
	tmp_function = to_res->function_from->next;
	while (tmp_function && !done)
	{
		if (ft_strcmp(to_res->label_to_seek, tmp_function->label) == 0)
		{
			if (to_res->has_param_byte)
				bytes_inbetween += 1;
			replace_bytes(to_res->byte_to_override, &bytes_inbetween,
									to_res->byte_to_override->content_size);
			done = 1;
		}
		bytes_inbetween += tmp_function->bytes_written;
		tmp_function = tmp_function->next;
	}
	return (!done ? 0 : 1);
}

int				resolve_unresolved_labels(t_list *labels_to_resolve)
{
	t_to_resolve	*to_res;
	char			done;

	while (labels_to_resolve)
	{
		done = 0;
		to_res = ((t_to_resolve*)labels_to_resolve->content);
		done = resolve_unresolved_labels_after(labels_to_resolve, to_res);
		if (!done && !resolve_unresolved_labels_bef(to_res))
			return (label_not_found(to_res->label_to_seek));
		labels_to_resolve = labels_to_resolve->next;
	}
	return (1);
}
