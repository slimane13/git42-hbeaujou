/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_header_to_bytes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:20:04 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/20 15:21:35 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_to_bytecode.h"

t_list		*add_header_to_bytes3(t_instruct *comment, t_list **bytes_end)
{
	t_list			*prog_size;
	int				x;
	int				i;
	unsigned char	zero;

	zero = 0;
	if (!(prog_size = ft_lstnew(NULL, 0)))
		return (NULL);
	ft_lstaddend(bytes_end, prog_size);
	x = 0;
	while (comment->name[x])
	{
		ft_lstaddend(bytes_end, ft_lstnew(&comment->name[x], sizeof(char)));
		x++;
	}
	i = x;
	while (i < COMMENT_LENGTH)
	{
		ft_lstaddend(bytes_end, ft_lstnew(&zero, sizeof(unsigned char)));
		i++;
	}
	return (prog_size);
}

t_list		*add_header_to_bytes2(t_instruct *name, t_instruct *comment,
															t_list **bytes_end)
{
	int				i;
	int				x;
	unsigned char	zero;

	zero = 0;
	if (ft_strlen(name->name) > PROG_NAME_LENGTH
		|| ft_strlen(comment->name) > COMMENT_LENGTH)
		return (big_error_null());
	x = 0;
	while (name->name[x])
	{
		ft_lstaddend(bytes_end, ft_lstnew(&name->name[x], sizeof(char)));
		x++;
	}
	i = x;
	while (i < PROG_NAME_LENGTH)
	{
		ft_lstaddend(bytes_end, ft_lstnew(&zero, sizeof(unsigned char)));
		i++;
	}
	return (add_header_to_bytes3(comment, bytes_end));
}

t_list		*add_header_to_bytes(t_function *functions, t_list **bytes_end)
{
	t_instruct	*name;
	t_instruct	*comment;

	if (functions->header != 1)
		return (big_error_null());
	if (ft_strcmp(functions->lines->content->name, NAME_CMD_STRING) == 0
		&& ft_strcmp(functions->lines->next->content->name, COMMENT_CMD_STRING)
																		== 0)
	{
		name = functions->lines->content->next;
		comment = functions->lines->next->content->next;
	}
	else if (ft_strcmp(functions->lines->next->content->name, NAME_CMD_STRING)
																			== 0
		&& ft_strcmp(functions->lines->content->name, COMMENT_CMD_STRING) == 0)
	{
		name = functions->lines->next->content->next;
		comment = functions->lines->content->next;
	}
	else
		return (big_error_null());
	return (add_header_to_bytes2(name, comment, bytes_end));
}

int			add_magic_to_bytes_end(t_list **bytes_end, t_list *tmp_list)
{
	ft_lstaddend(bytes_end, tmp_list);
	return (1);
}

int			add_exec_magic_to_bytes(t_list **bytes, t_list **bytes_end)
{
	unsigned int	tmp;
	unsigned char	tmp_char;
	t_list			*tmp_list;

	tmp = COREWAR_EXEC_MAGIC;
	tmp_char = tmp / (256 * 256 * 256);
	tmp -= (tmp_char * 256 * 256 * 256);
	if (!(tmp_list = ft_lstnew(&tmp_char, sizeof(unsigned char))))
		return (0);
	ft_lstaddend(bytes_end, tmp_list);
	*bytes = *bytes_end;
	tmp_char = tmp / (256 * 256);
	tmp -= (tmp_char * 256 * 256);
	if (!(tmp_list = ft_lstnew(&tmp_char, sizeof(unsigned char))))
		return (0);
	ft_lstaddend(bytes_end, tmp_list);
	tmp_char = tmp / 256;
	tmp -= (tmp_char * 256);
	if (!(tmp_list = ft_lstnew(&tmp_char, sizeof(unsigned char))))
		return (0);
	ft_lstaddend(bytes_end, tmp_list);
	tmp_char = tmp;
	if (!(tmp_list = ft_lstnew(&tmp_char, sizeof(unsigned char))))
		return (0);
	return (add_magic_to_bytes_end(bytes_end, tmp_list));
}
