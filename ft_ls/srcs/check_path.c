/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_chem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 06:12:12 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/01 06:14:32 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putstr_chem(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s) - 1);
	else if (s == NULL)
		ft_putendl("(NULL)");
}
