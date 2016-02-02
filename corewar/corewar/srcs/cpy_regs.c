/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:03:28 by dbousque          #+#    #+#             */
/*   Updated: 2016/01/31 12:31:03 by skirkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		*copy_regs(int *registres)
{
	int		*res;
	int		i;

	if (!(res = (int*)malloc(sizeof(int) * REG_NUMBER)))
		return (NULL);
	i = 0;
	while (i < REG_NUMBER)
	{
		res[i] = registres[i];
		i++;
	}
	return (res);
}
