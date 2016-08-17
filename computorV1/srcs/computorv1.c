/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 09:03:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/08/17 17:31:53 by hbeaujou         ###   ########.fr       */
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
		if(ft_atoi(tmp) != 0)
			g_some=1;
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
		if(ft_atoi(tmp) != 0)
			g_some=1;
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
		if (tmp2->value != 0)
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
		else {
			tmp2 = tmp2->next;
		}
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

void	check_if_all_null(t_equ **equ)
{
	t_equ *tmp;
	t_elem *elem;

	tmp = *equ;
	elem = tmp->content;
	while(elem)
	{
		if (elem->value != 0)
			g_some = 0;
		elem = elem->next;
	}

}

double	solve(t_equ **equ, int degree)
{
	double	a = 0;
	double	b = 0;
	double	c = 0;
	double	res;
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

void	add_0_beggining_1(t_equ **equ, int equ_num)
{
	t_elem	*tmp;

	tmp = new_elem(0,0);
	if (equ_num == 0)
	{
		tmp->next = (*equ)->content;
		(*equ)->content = tmp;
	} 
	else
	{
		tmp->next = (*equ)->next->content;
		(*equ)->next->content = tmp;
	}
}

void	add_both_beggining_2(t_equ **equ, int equ_num)
{
	t_elem	*tmp;
	t_elem	*tmp1;

	tmp = new_elem(0,0);
	tmp1 = new_elem(0,1);
	tmp->next = tmp1;
	if (equ_num == 0)
	{
		tmp1->next = (*equ)->content;
		(*equ)->content = tmp;
	}
	else
	{
		tmp1->next = (*equ)->next->content;
		(*equ)->next->content = tmp;
	}
}

void	add_0_beggining_2(t_equ **equ, int equ_num)
{
	t_elem	*tmp;

	tmp = new_elem(0,1);
	if (equ_num == 0)
	{
		tmp->next = (*equ)->content->next;
		(*equ)->content->next = tmp;
	}
	else
	{
		tmp->next = (*equ)->next->content->next;
		(*equ)->next->content->next = tmp;
	}
}

void	add_both_last(t_equ **equ, int equ_num)
{
	t_elem	*tmp;
	t_elem	*tmp1;

	tmp = new_elem(0,1);
	tmp1 = new_elem(0,2);
	tmp->next = tmp1;
	if (equ_num == 0)
		(*equ)->content->next = tmp;
	else
		(*equ)->next->content->next = tmp;
}

void	add_2_last(t_equ **equ, int equ_num)
{
	t_elem	*tmp;

	tmp = new_elem(0,2);
	if (equ_num == 0)
		(*equ)->content->next->next = tmp;
	else
		(*equ)->next->content->next->next = tmp;
}

void	complete(t_equ **equ)
{
	t_equ	*tmp_equ;
	t_elem	*tmp;
	int		count;
	int		equ_num;

	tmp_equ = *equ;
	equ_num = 0;
	while (tmp_equ)
	{
		count = 0;
		tmp = tmp_equ->content;
		while (tmp)
		{
			if (tmp->puissance == 1 && count == 0)
			{
				add_0_beggining_1(equ, equ_num);
				count++;
			}
			else if (tmp->puissance == 1 && count > 1)
			{
				ft_printf("Erreur de puissance\n");
				exit(0);
			}
			else if (tmp->puissance == 2 && count == 0)
			{
				add_both_beggining_2(equ, equ_num);
				count = count + 2;
			}
			else if (tmp->puissance == 2 && count == 1)
			{
				add_0_beggining_2(equ, equ_num);
				count++;
			}
			else if (tmp->puissance == 2 && count > 2)
			{
				ft_printf("Erreur de puissance\n");
				exit(0);
			}
			
			if (tmp->next == NULL && tmp->puissance == 0)
				add_both_last(equ, equ_num);
			else if (tmp->next == NULL && tmp->puissance == 1)
				add_2_last(equ, equ_num);
			
			count++;
			tmp = tmp->next;
		}
		tmp_equ = tmp_equ->next;
		equ_num++;
	}
}

int		main(int argc, char **argv)
{
	char		*str;
	int			degree;
	int			flag = 1;
	double		discri;
	t_equ		*equ;
	t_solve		*answ;
	
	if (argc > 0)
		;
	g_some = 0;
	if (argv[1])
		str = deblank(argv[1]);
	else
	{
		while (flag == 1)
		{
			get_next_line(0, &str);
			if (str != NULL)
			{
				if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
					str = ft_strsub(str, 1, ft_strlen(str)-2);
				if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z' && str[0] != 'X'))
				{
					printf("Lettres non supportees\n");
					exit(0);
				}
				str = deblank(str);
				flag = 0;
			}
		}
	}
	parsing(&equ, str);
	complete(&equ);
	reduce(&equ);
	check_if_all_null(&equ);
	ft_printf("\n [0;36;40m----- Demarrage de la resolution ----- \n\n");
	ft_printf("[0;37;40mForme reduite : ");
	affiche_end(&equ);
	degree = check(&equ);
	ft_printf("Degre : %d\n\n", degree);
	if (degree == 2)
	{
		discri = solve(&equ, degree);
		ft_printf("Discriminant : %f\n", discri);
		if (discri < 0)
		{
			ft_printf("Discriminant negatif, les solutions son complexes\n");
			ft_printf("S1 = (-1 - i%f)/2\n", sqrt(-discri));
			ft_printf("S2 = (-1 + i%f)/2\n", sqrt(-discri));
			ft_printf("\n [0;31;40m----- Fin de la resolution ----- \n\n");
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
	else if (degree == 1)
		solve_degree_1(&equ, &answ);
	else
		ft_printf("Degre trop grand pour etre resolu\n");
	affiche_solve(&answ);
	ft_printf("\n [0;31;40m----- Fin de la resolution ----- \n\n");
}
