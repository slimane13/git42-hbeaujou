/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_bytecode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:24:25 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/21 18:09:05 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_to_bytecode.h"

int					write_void_byte(t_list **bytes_end)
{
	t_list			*tmp;
	unsigned char	zero;

	zero = 0;
	if (!(tmp = ft_lstnew(&zero, sizeof(unsigned char))))
		return (0);
	ft_lstaddend(bytes_end, tmp);
	return (1);
}

t_bytes_n_labels	*get_bytes_n_labels(t_list **bytes_end)
{
	t_bytes_n_labels	*res;

	if (!(res = (t_bytes_n_labels*)malloc(sizeof(t_bytes_n_labels))))
		return (NULL);
	res->bytes_end = *bytes_end;
	res->labels_to_resolve = NULL;
	res->labels_to_resolve_end = NULL;
	return (res);
}

int					add_functions(t_function *functions, t_list **bytes_end)
{
	t_function			*tmp_func;
	t_line				*tmp_line;
	t_instruct			*tmp_i;
	t_bytes_n_labels	*bytes_n_labels;

	bytes_n_labels = get_bytes_n_labels(bytes_end);
	tmp_func = functions;
	while (tmp_func)
	{
		tmp_func->bytes_written = 0;
		tmp_line = tmp_func->lines;
		while (tmp_line)
		{
			tmp_i = tmp_line->content;
			if (!(write_opcode(tmp_i->opcode, &(bytes_n_labels->bytes_end))))
				return (big_error());
			tmp_func->bytes_written += 1;
			if (!(write_param_byte_if_nec(tmp_i, &(bytes_n_labels->bytes_end),
	tmp_func)) || !(write_params(tmp_i, tmp_func, functions, bytes_n_labels)))
				return (big_error());
			tmp_line = tmp_line->next;
		}
		tmp_func = tmp_func->next;
	}
	return (resolve_unresolved_labels(bytes_n_labels->labels_to_resolve));
}

int					convert_to_binary(t_function *functions, char *filename)
{
	t_list		*bytes;
	t_list		*bytes_end;
	t_list		*size_bytes;

	bytes = NULL;
	bytes_end = NULL;
	if (!(add_exec_magic_to_bytes(&bytes, &bytes_end)))
		return (0);
	if (!(size_bytes = add_header_to_bytes(functions, &bytes_end)))
		return (0);
	if (!(add_functions(functions->next, &bytes_end)))
		return (0);
	if (!(update_size_bytes(size_bytes, functions->next)))
		return (0);
	return (write_bytes_to_file(filename, bytes));
}

int					convert_to_bytecode(t_function *functions, char *filename)
{
	if (!(merge_first_two_functions(&functions)))
		return (0);
	convert_to_binary(functions, filename);
	return (0);
}
