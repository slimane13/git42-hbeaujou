/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 11:18:13 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/07 11:49:30 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int		ft_check_1(int ac, t_stack *a)
{
	(void)ac;
	if (a->nb_elem == 3 && a->next->nb > a->next->next->nb &&
			a->next->next->nb > a->next->next->next->nb)
	{
		swap(&a);
		ft_printf("SA ");
		rev_rotate(&a);
		ft_printf("RRA ");
		g_coups = 2;
	}
	return (0);
}

void	ft_check_2(char **av, int ac, int *tab_nb, t_stack **a)
{
	int i;
	int j;

	(void)av;
	i = 1;
	while (i < ac)
	{
		j = 1;
		while (j < ac)
		{
			if (tab_nb[i] == tab_nb[j] && i != j)
			{
				ft_printf("Error\n");
				exit(-1);
			}
			j++;
		}
		i++;
	}
	ft_check_1(ac, *a);
}

void	check_bonus(char **av, int *i)
{
	if (!ft_strcmp(av[1], "-nr") || !ft_strcmp(av[1], "-rn") ||
			!ft_strcmp(av[1], "-r") || !ft_strcmp(av[1], "-n"))
		*i = *i + 1;
	if (!ft_strcmp(av[1], "-nr") || !ft_strcmp(av[1], "-rn"))
	{
		g_total = 1;
		g_res = 1;
	}
	else if (!ft_strcmp(av[1], "-n"))
		g_total = 1;
	else if (!ft_strcmp(av[1], "-r"))
		g_res = 1;
}

void	ft_check_3(char **av, int ac, t_stack **a)
{
	t_stack	*tmp;
	int		*tab_nb;
	int		i;

	i = 1;
	tmp = *a;
	if (!(tab_nb = (int *)malloc(sizeof(int) * ac)))
		return ;
	check_bonus(av, &i);
	while (av[i])
	{
		if (ft_is_int(av[i]))
		{
			ft_list_back(&tmp, ft_atoi(av[i]));
			tab_nb[i] = ft_atoi(av[i]);
		}
		else
		{
			ft_printf("Error\n");
			exit(0);
		}
		i++;
	}
	ft_check_2(av, ac, tab_nb, a);
}

void	affiche(t_stack *l_a)
{
	t_stack *tmp;

	tmp = l_a;
	while (tmp->next != l_a)
	{
		ft_printf("[%d] ", tmp->next->nb);
		tmp = tmp->next;
	}
}
