/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:32:56 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/29 13:54:08 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag_number(char **str, int count[3], int *nbr, char *c)
{
	int flag;

	*nbr = *nbr;
	if (str[count[0]][0] == '.' || (str[count[0]][0] == '0' &&
				str[count[0]][1] == '.'))
	{
		*c = '.';
		if (ft_isalpha(str[count[0]][1]) != 0)
			return (0);
		flag = ft_atoi_spec(str[count[0]]);
	}
	else if (str[count[0]][0] == '-' && str[count[0]][1] == '.')
	{
		str[count[0]][0] = '0';
		if (*c == 'h')
			flag = ft_atoi_length(str[count[0]]);
		else
			flag = ft_atoi_spec(str[count[0]]);
		*c = '.';
	}
	else if (str[count[0]][0] == '-' && str[count[0]][1] == '0')
	{
		*c = '0';
		flag = ft_atoi(str[count[0]]);
	}
	else if (str[count[0]][0] == '0')
	{
		*c = '0';
		flag = ft_atoi(str[count[0]]);
	}
	else
		flag = ft_atoi(str[count[0]]);
	return (flag);
}

void	attrib_p(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_p(&t_v, str, count);
	if (var[count[2]]->u_long != 0 && t_v.flag != 3500)
	{
		str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_long, "0123456789abcdef");
		t_v.nbr = ft_strlen(str[count[0]]);
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
		t_v.nbr = ft_strlen(str[count[0]]) + 2;
	}
	if (t_v.flag == 3500)
		ft_cut_flag_p1(&t_v, var, str, count);
	else if (var[count[2]]->u_long == 0 && t_v.c != '.')
		str[count[0]] = ft_strdup("0x0");
	else if (t_v.flag != 3500 && var[count[2]]->u_long == 0)
		str[count[0]] = ft_strdup("0x");
	if (t_v.flag != 0 && t_v.flag < 1000)
		ft_cut_flag_p2(&t_v, var, str, count);
	count[2]++;
}

void	attrib_x(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_x(&t_v, var, str, count);
	if (t_v.flag == 5000)
		ft_cut_flag_x1(&t_v, var, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_x2(&t_v, var, str, count);
	else if (t_v.flag == 3500)
		ft_cut_flag_x3(&t_v, var, str, count);
	if (t_v.flag != 0 && t_v.flag != -1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3500 && t_v.flag != 3000 && t_v.flag != 5000 && t_v.spec == 0)
		ft_cut_flag_x4(&t_v, str, count);
	else if (t_v.flag == 0 && t_v.c == '.' && t_v.spec == 0)
		str[count[0]][0] = '\0';
	count[2]++;
}

void	attrib_x_maj(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_x_maj(&t_v, var, str, count);
	if (t_v.flag == 5000)
		ft_cut_flag_x1_maj(var, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_x2_maj(&t_v, var, str, count);
	else if (t_v.flag == 3500)
		ft_cut_flag_x3_maj(&t_v, var, str, count);
	else if (t_v.flag != 0 && t_v.flag != -1 && t_v.flag != 1000 && t_v.flag != 3500 &&
			t_v.flag != 2000 && t_v.flag != 5000)
		ft_cut_flag_x4_maj(&t_v, str, count);
	else if (t_v.flag == 0 && t_v.c == '.')
		str[count[0]][0] = '\0';
	count[2]++;
}

void	attrib_o(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	int flag_save;
	int k;
	int l;
	int check;
	int diff;
	int check_double;
	int p;
	int spec;
	char c;

	k = 0;
	p = 1;
	spec = 1;
	diff = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->entier);
	check_double = ft_atoi_double(str[count[0]]);
	check = ft_atoi_ultra(str[count[0]]);
	if (var[count[2]]->entier < 0)
		nbr++;
	flag = check_flag(str, count, &nbr, &c);
	l = ft_atoi_spec_o(str[count[0]]);
	var[count[2]]->u_entier = (unsigned int)var[count[2]]->entier;
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_entier, "01234567");
	nbr = ft_strlen(str[count[0]]);
	if (flag == 1000 && var[count[2]]->entier > 0)
	{
	}
	else if (flag == 5000 && var[count[2]]->entier >= 0)
	{
		if (var[count[2]]->entier != 0)
		{
			if (check == 0 && check_double == 0)
				str[count[0]] = ft_strjoin("0", str[count[0]]);
			while (k < check_double - nbr)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
			}
		}
		else if (var[count[2]]->entier == 0)
			spec = 0;
		flag_save = flag;
		flag = l;
	}
	else if (flag == 3000)
	{
		if (var[count[2]]->stars < 0)
		{
			while (k > var[count[2]]->stars + nbr - 1)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else
		{
			while (k < var[count[2]]->stars - nbr + 1)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	else if (flag == 3500)
	{
		if (check_double >= nbr)
			diff = check_double;
		else
			diff = nbr;
		if (var[count[2]]->entier < 0)
		{
			str[count[0]] = ft_strsub(str[count[0]], 1, ft_nbrlen(var[count[2]]->entier) + 1);
			if (check < check_double)
				k = -1;
			while (k < check_double - nbr - 1)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
				p = 0;
			}
			str[count[0]] = ft_strjoin("-", str[count[0]]);
			while (p < check - diff)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				p++;
			}
		}
		else
		{
			while (k < check_double - nbr)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
			}
			k = 0;
			while (k < check - diff)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	if (flag != 0 && flag != -1 && flag != 1000 && flag != 3500 &&
			flag != 2000 && flag != 3000 && flag != 5000)
	{
		if (flag < -1 && c != '0')
		{
			while (k > flag + nbr)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else if (flag > 0 && (c == '0' || c == '.'))
		{
			while (k < flag - nbr)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
			}
		}
		else if (flag < -1 && c == '0')
		{
			while (k > flag)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k--;
			}
		}
		else
		{
			while (k < flag - nbr)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	else if (flag_save == 0 && c == '.' && spec == 1)
		str[count[0]][0] = '\0';
	else if (var[count[2]]->entier == 0 && c == '.' && spec == 1)
		str[count[0]][0] = '\0';
	count[2]++;
}
