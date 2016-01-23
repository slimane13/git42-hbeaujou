/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 09:14:42 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/23 15:41:42 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

char	*deblank(char* input)
{
	int i;
	int j;
	char *output;
	
	output = input;
	i = 0;
	j = 0;
	while (i < (int)ft_strlen(input))
	{
		if (input[i] != ' ' && input[i] != '\t')
			output[j] = input[i];
		else
			j--;
		i++;
		j++;
	}
	output[j] = 0;
	return (output);
}

t_elem	*new_elem(double valu, int puissanc)
{
	t_elem	*res;

	res = (t_elem *)malloc(sizeof(t_elem));
	res->value = valu;
	res->puissance = puissanc;
	res->next = NULL;
	return (res);
}

t_equ	*new_equ(t_elem *conten)
{
	t_equ	*res;

	res = (t_equ *)malloc(sizeof(t_equ));
	res->content = conten;
	res->next = NULL;
	return (res);
}

t_solve	*new_solve(double valu)
{
	t_solve	*res;

	res = (t_solve *)malloc(sizeof(t_solve));
	res->value = valu;
	res->next = NULL;
	return (res);
}

void	ft_lstaddend_elem(t_elem **alst, t_elem *new_r)
{
	t_elem	*tmp;

	tmp = *alst;
	if (!tmp)
		*alst = new_r;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_r;
	}
}

void	ft_lstaddend_equ(t_equ **alst, t_equ *new_r)
{
	t_equ	*tmp;

	tmp = *alst;
	if (!tmp)
		*alst = new_r;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_r;
	}
}

void	ft_lstaddend_solve(t_solve **alst, t_solve *new_r)
{
	t_solve	*tmp;

	tmp = *alst;
	if (!tmp)
		*alst = new_r;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_r;
	}
}
