/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:14:34 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:14:35 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (alst && *alst)
	{
		if ((*alst)->next != NULL)
			ft_lstdel(&((*alst)->next), del);
		ft_lstdelone(alst, del);
	}
}
