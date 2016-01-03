/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:14:54 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:14:55 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freedel(t_list *lst)
{
	if (lst != NULL)
	{
		free(lst);
		lst = NULL;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !f)
		return (NULL);
	if (!(res = f(lst)))
		return (NULL);
	tmp2 = res;
	tmp = lst->next;
	while (tmp)
	{
		if (!(tmp2->next = f(tmp)))
		{
			ft_freedel(tmp);
			ft_freedel(tmp2);
			return (NULL);
		}
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	ft_freedel(tmp);
	ft_freedel(tmp2);
	return (res);
}
