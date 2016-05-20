/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:07:45 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:07:46 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cpy;

	new = (t_list *)ft_memalloc(sizeof(content_size));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		cpy = ft_memalloc(content_size);
		if (cpy == NULL)
			return (NULL);
		new->content = ft_memcpy(cpy, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
