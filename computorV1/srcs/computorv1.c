/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 09:03:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/22 11:14:08 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

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
		while ((str[*i] > '9' || str[*i] < '0') && str[*i] && str[*i] != '-')
			*i = *i + 1;
		*j = *i;
		while (str[*i] <= '9' && str[*i] >= '0')
			*i = *i + 1;
		tmp = ft_strsub(str, *j, *i - *j);
		elem = new_elem(coef, ft_atoi(tmp));
		ft_lstaddend_elem(&(*equ)->next->content, elem);
		while ((str[*i] > '9' || str[*i] < '0') && str[*i] && str[*i] == '-')
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
	while (tmp)
	{
		tmp2 = tmp->content;
		while (tmp2)
		{
			if (tmp2->puissance > max)
				max = tmp2->puissance;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (max);
}

int		floa_calc(char *str)
{
}

void	affiche(t_equ **equ)
{
	t_equ	*tmp;
	t_elem	*tmp2;
	char	str[50];
	int		floa;

	tmp = *equ;
	tmp2 = tmp->content;
	while (tmp2)
	{
		sprintf(str, "coef : %f | puissance : %d\n", tmp2->value, tmp2->puissance);
		floa = floa_calc(str);
		morphNumericString(str, floa);
		printf("%s\n", str);
		tmp2 = tmp2->next;
	}
	tmp = tmp->next;
	tmp2 = tmp->content;
	while (tmp2)
	{
		sprintf(str, "coef : %f | puissance : %d\n", tmp2->value, tmp2->puissance);
		morphNumericString(str, 3);
		printf("%s\n", str);
		tmp2 = tmp2->next;
	}
}

void	affiche_end(t_equ **equ)
{
	t_equ	*tmp;
	t_elem	*tmp2;

	tmp = *equ;
	tmp2 = tmp->content;
	while (tmp2)
	{
		printf("coef : %f | puissance : %d\n", tmp2->value, tmp2->puissance);
		tmp2 = tmp2->next;
	}
}

void	affiche_solve(t_solve **answ)
{
	t_solve	*tmp;
	int		i;

	tmp = *answ;
	i = 1;
	while (tmp)
	{
//		sprintf(str, "Solution n%d : %f\n", i, tmp->value);
//		morphNumericString(str, 3);
		printf("Solution n%d : %f\n", i, tmp->value);
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
		if (tmp->puissance == 0)
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
		if (tmp->puissance == 0)
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

	str = deblank(argv[1]);
	parsing(&equ, str);
	affiche(&equ);
	degree = check(&equ);
	ft_printf("Degre : %d\n", degree);
	reduce(&equ);
	affiche_end(&equ);
	discri = solve(&equ, degree);
	ft_printf("Discriminant : %d\n", discri);
	if (discri < 0)
	{
		ft_printf("Discriminant negatif, il n'y a pas de solution\n");
		exit(0);
	}
	else if (discri > 0)
		find_solv(&equ, &answ);
	affiche_solve(&answ);
}
