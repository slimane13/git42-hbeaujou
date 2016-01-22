/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_bytecode_utils2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:22:10 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/20 15:53:59 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_to_bytecode.h"

int			update_size_bytes(t_list *size_bytes, t_function *functions)
{
	unsigned long long	prog_len;
	unsigned int		*res;

	prog_len = 0;
	while (functions)
	{
		prog_len += functions->bytes_written;
		functions = functions->next;
	}
	if (!(res = (unsigned int*)malloc(sizeof(unsigned int))))
		return (big_error());
	*res = (unsigned int)prog_len;
	size_bytes->content = res;
	size_bytes->content_size = sizeof(unsigned int);
	return (1);
}

int			merge2(t_function **functions, t_function *new_f)
{
	new_f->lines->content->next->next = NULL;
	new_f->lines->next->content->next->next = NULL;
	new_f->lines->content->name = ft_strdup(NAME_CMD_STRING);
	new_f->lines->next->content->name = ft_strdup(COMMENT_CMD_STRING);
	if ((*functions)->header == 1)
	{
		(*functions)->label[ft_strlen((*functions)->label) - 1] = '\0';
		new_f->lines->content->next->name = ft_strdup((*functions)->label + 1);
		(*functions)->next->label[ft_strlen((*functions)->next->label) - 1] =
																		'\0';
		new_f->lines->next->content->next->name =
									ft_strdup((*functions)->next->label + 1);
	}
	else
	{
		(*functions)->label[ft_strlen((*functions)->label) - 1] = '\0';
		new_f->lines->next->content->next->name =
											ft_strdup((*functions)->label + 1);
		(*functions)->next->label[ft_strlen((*functions)->next->label) - 1] =
																		'\0';
		new_f->lines->content->next->name =
									ft_strdup((*functions)->next->label + 1);
	}
	*functions = new_f;
	return (1);
}

int			merge_first_two_functions(t_function **functions)
{
	t_function	*new_func;

	if (!(new_func = (t_function*)malloc(sizeof(t_function))))
		return (big_error());
	new_func->label = NULL;
	new_func->header = 1;
	new_func->bytes_written = 0;
	new_func->next = (*functions)->next->next;
	if (!(new_func->lines = (t_line*)malloc(sizeof(t_line))))
		return (big_error());
	if (!(new_func->lines->next = (t_line*)malloc(sizeof(t_line))))
		return (big_error());
	if (!(new_func->lines->content = (t_instruct*)malloc(sizeof(t_instruct))))
		return (big_error());
	if (!(new_func->lines->next->content =
									(t_instruct*)malloc(sizeof(t_instruct))))
		return (big_error());
	if (!(new_func->lines->content->next =
									(t_instruct*)malloc(sizeof(t_instruct))))
		return (big_error());
	if (!(new_func->lines->next->content->next =
									(t_instruct*)malloc(sizeof(t_instruct))))
		return (big_error());
	new_func->lines->next->next = NULL;
	return (merge2(functions, new_func));
}
