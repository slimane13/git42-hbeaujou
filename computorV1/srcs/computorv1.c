/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 09:03:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/23 15:41:23 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

int	g_some;

void	morphNumericString(char *s, int n)
{
	char *p;
	int count;

	p = strchr(s,'.');
	if (p != NULL)
	{
		count = n;
		while (count >= 0)
		{
			count--;
			if (*p == '\0')
				break ;
			p++;
		}
		*p-- = '\0';
		while (*p == '0')
			*p-- = '\0';
		if (*p == '.')
			*p = '\0';
	}
}

void	before_equal(int *i, int *j, char *str, t_equ **equ)
{
	t_elem	*elem;
	char	*tmp;
	double	coef;

	while (str[*i] != '=' && str[*j] != '=')
	{
		*j = *i;
		while ((str[*i] <= '9' && str[*i] >= '0') || str[*i] == '.' || str[*i] == '-')
			*i = *i + 1;
		tmp = ft_strsub(str, *j, *i - *j);
		coef = atof(tmp);
		if (coef != 0)
			g_some = 1;
		while ((str[*i] > '9' || str[*i] < '0') && str[*i] != '=' && str[*i] != '-')
			*i = *i + 1;
		*j = *i;
		while (str[*i] <= '9' && str[*i] >= '0')
			*i = *i + 1;
		tmp = ft_strsub(str, *j, *i - *j);
		elem = new_elem(coef, ft_atoi(tmp));
		ft_lstaddend_elem(&(*equ)->content, elem);
		while ((str[*i] > '9' || str[*i] < '0') && str[*i] != '=' && str[*i] != '-')
			*i = *i + 1;
	}
}

void	after_equal(int *i, int *j, char *str, t_equ **equ)
{
	t_elem	*elem;
	char	*tmp;
	double	coef;

	while (str[*i] && str[*j])
	{
		*j = *i;
		while ((str[*i] <= '9' && str[*i] >= '0') || str[*i] == '.' || str[*i] == '-')
			*i = *i + 1;
		tmp = ft_strsub(str, *j, *i - *j);
		coef = atof(tmp);
		if (coef != 0)
			g_some = 1;
		while ((str[*i] > '9' || str[*i] < '0') && str[*i] && str[*i] != '-')
			*i = *i + 1;
		*j = *i;
		while (str[*i] <= '9' && str[*i] >= '0')
			*i = *i + 1;
		tmp = ft_strsub(str, *j, *i - *j);
		elem = new_elem(coef, ft_atoi(tmp));
		ft_lstaddend_elem(&(*equ)->next->content, elem);
		while ((str[*i] > '9' || str[*i] < '0') && str[*i] && str[*i] != '-')
			*i = *i + 1;
	}
}

void	parsing(t_equ **equ, char *str)
{
	t_equ	*equ2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	*equ = new_equ(NULL);
	before_equal(&i, &j, str, equ);
	i++;
	equ2 = new_equ(NULL);
	ft_lstaddend_equ(equ, equ2);
	after_equal(&i, &j, str, equ);
}

int		check(t_equ **equ)
{
	t_equ	*tmp;
	t_elem	*tmp2;
	int		max;

	tmp = *equ;
	max = 0;
	tmp2 = tmp->content;
	while (tmp2)
	{
		if (tmp2->puissance > max && tmp2->value != 0)
			max = tmp2->puissance;
		tmp2 = tmp2->next;
	}
	return (max);
}

int		floa_calc(char *str)
{
	int	i;
	int k;
	int	count;

	count = 0;
	i = 0;
	k = 0;
	while (str[i] != '.')
		i++;
	k = i;
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			k = i;
		i++;
	}
	return (k);
}

void	affiche_end(t_equ **equ)
{
	t_equ	*tmp;
	t_elem	*tmp2;
	char	str[50];
	char	str2[50];
	int		floa;
	int		count;

	tmp = *equ;
	tmp2 = tmp->content;
	count = 0;
	while (tmp2)
	{
		sprintf(str2, "%f", tmp2->value);
		floa = floa_calc(str2);
		morphNumericString(str2, floa);
		sprintf(str, "%s * X^%d ", str2, tmp2->puissance);
		if (count > 0 && tmp2->value >= 0)
			printf("+ ");
		printf("%s", str);
		tmp2 = tmp2->next;
		count++;
	}
	printf("= 0");
	printf("\n");
}

void	affiche_solve(t_solve **answ)
{
	t_solve	*tmp;
	int		i;
	int		floa;
	char	str2[50];

	tmp = *answ;
	i = 1;
	while (tmp)
	{
		sprintf(str2, "%f", tmp->value);
		floa = floa_calc(str2);
		morphNumericString(str2, floa);
		printf("S%d = %s\n", i, str2);
		tmp = tmp->next;
		i++;
	}
}

void	reduce(t_equ **equ)
{
	t_equ	*equ1;
	t_elem	*elem1;
	t_elem	*elem2;

	equ1 = *equ;
	elem1 = equ1->content;
	while (elem1)
	{
		elem2 = equ1->next->content;
		while (elem2)
		{
			if (elem1->puissance == elem2->puissance)
				elem1->value = elem1->value - elem2->value;
			elem2 = elem2->next;
		}
		elem1 = elem1->next;
	}
}

int		solve(t_equ **equ, int degree)
{
	int		a;
	int		b;
	int		c;
	int		res;
	t_elem	*tmp;

	if (degree > 2)
	{
		ft_printf("Degree superieur a 2\n");
		exit(0);
	}
	tmp = (*equ)->content;
	while (tmp)
	{
		if (tmp->puissance == 2)
			a = tmp->value;
		else if (tmp->puissance == 1)
			b = tmp->value;
		else
			c = tmp->value;
		tmp = tmp->next;
	}
	res = b * b - 4 * a * c;
	return (res);
}

void	solve_degree_1(t_equ **equ, t_solve **answ)
{
	double	a;
	double	b;
	double	ans;
	t_elem	*tmp;
	t_solve	*tmp2;

	tmp = (*equ)->content;
	while (tmp)
	{
		if (tmp->puissance == 1)
			a = tmp->value;
		else if (tmp->puissance == 0)
			b = tmp->value;
		tmp = tmp->next;
	}
	if (a == 0)
	{
		printf("Il n'y a pas de solution\n");
		printf("\n [0;31;40m----- Fin de la resolution ----- \n\n");
		exit(0);
	}
	printf("Il n'y a qu'une solution :\n");
	ans = -b / a;
	tmp2 = new_solve(ans);
	ft_lstaddend_solve(answ, tmp2);
}

void	solve_zero(t_equ **equ, t_solve **answ)
{
	double	a;
	double	b;
	double	c;
	double	res;
	double	ans;
	t_elem	*tmp;
	t_solve	*tmp2;

	tmp = (*equ)->content;
	while (tmp)
	{
		if (tmp->puissance == 2)
			a = tmp->value;
		else if (tmp->puissance == 1)
			b = tmp->value;
		else
			c = tmp->value;
		tmp = tmp->next;
	}
	res = b * b - 4 * a * c;
	ans = (-b) / (2 * a);
	tmp2 = new_solve(ans);
	ft_lstaddend_solve(answ, tmp2);
}

void	find_solv(t_equ **equ, t_solve **answ)
{
	double	a;
	double	b;
	double	c;
	double	res;
	double	ans;
	t_elem	*tmp;
	t_solve	*tmp2;

	tmp = (*equ)->content;
	while (tmp)
	{
		if (tmp->puissance == 2)
			a = tmp->value;
		else if (tmp->puissance == 1)
			b = tmp->value;
		else
			c = tmp->value;
		tmp = tmp->next;
	}
	res = b * b - 4 * a * c;
	ans = (-b - sqrt(res)) / (2 * a);
	tmp2 = new_solve(ans);
	ft_lstaddend_solve(answ, tmp2);
	ans = (-b + sqrt(res)) / (2 * a);
	tmp2 = new_solve(ans);
	ft_lstaddend_solve(answ, tmp2);
}

int		main(int argc, char **argv)
{
	char		*str;
	int			degree;
	int			discri;
	t_equ		*equ;
	t_solve		*answ;

	if (argc > 0)
		;
	g_some = 0;
	str = deblank(argv[1]);
	parsing(&equ, str);
	reduce(&equ);
	ft_printf("\n [0;36;40m----- Demarrage de la resolution ----- \n\n");
	ft_printf("[0;37;40mForme reduite : ");
	affiche_end(&equ);
	degree = check(&equ);
	ft_printf("Degre : %d\n\n", degree);
	if (degree == 2)
	{
		discri = solve(&equ, degree);
		ft_printf("Discriminant : %d\n", discri);
		if (discri < 0)
		{
			ft_printf("Discriminant negatif, il n'y a pas de solution\n");
			exit(0);
		}
		else if (discri == 0)
		{
			ft_printf("Discriminant nul, il n'y a qu'une solution :\n");
			solve_zero(&equ, &answ);
		}
		else
		{
			ft_printf("Discriminant positif, il y a 2 solutions :\n");
			find_solv(&equ, &answ);
		}
	}
	else if (degree == 0)
	{
		if (g_some != 0)
			ft_printf("Tous les reels sont solutions\n");
		else
			ft_printf("Il n'y a aucune solution\n");
	}
	else
		solve_degree_1(&equ, &answ);
	affiche_solve(&answ);
	ft_printf("\n [0;31;40m----- Fin de la resolution ----- \n\n");
}
