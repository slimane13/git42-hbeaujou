/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:06:43 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:06:45 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_list;
	t_list	*tmp;

	tmp = *alst;
	while (tmp)
	{
		next_list = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = next_list;
	}
	*alst = NULL;
}
