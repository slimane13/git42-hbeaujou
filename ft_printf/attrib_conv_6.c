/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 20:35:31 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 15:49:51 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <wchar.h>
#include "ft_printf.h"

void	attrib_o_char(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_o_char(&t_v, var, str, count);
	if (t_v.flag == 1000)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 5000)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		t_v.flag = t_v.l;
	}
	else if (t_v.flag == 3000)
		ft_cut_flag_o1_char(&t_v, var, str, count);
	if (t_v.flag != -1 && t_v.flag != 1000 &&
			t_v.flag != 2000 && t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_o2_char(&t_v, str, count);
	count[2]++;
}

void	attrib_x_char(char **str, t_var **var, int count[3])
{
	t_cut t_v ;

	ft_cut_init_x_char(&t_v, var, str, count);
	if (t_v.flag == 1000)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 5000)
	{
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
		t_v.flag = t_v.l;
		t_v.nbr++;
	}
	else if (t_v.flag == 3000)
		ft_cut_flag_x1_char(&t_v, var, str, count);
	if (t_v.flag != -1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_x2_char(&t_v, str, count);
	if (t_v.c != '.' && t_v.c != '0')
	{
		while (str[count[0]][0] == '0' && str[count[0]][1] != '\0')
			str[count[0]] = ft_strsub(str[count[0]], 1, ft_strlen(str[count[0]]));
	}
	count[2]++;
}

void	attrib_x_maj_char(char **str, t_var **var, int count[3])
{
	t_cut t_v ;

	ft_cut_init_x_mchr(&t_v, var, str, count);
	if (t_v.flag == 1000)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 5000)
	{
		str[count[0]] = ft_strjoin("0X", str[count[0]]);
		t_v.flag = t_v.l;
		t_v.nbr++;
	}
	else if (t_v.flag == 3000)
		ft_cut_flag_x1_mchr(&t_v, var, str, count);
	if (t_v.flag != -1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_x2_mchr(&t_v, str, count);
	if (t_v.c != '.' && t_v.c != '0')
	{
		while (str[count[0]][0] == '0' && str[count[0]][1] != '\0')
			str[count[0]] = ft_strsub(str[count[0]], 1, ft_strlen(str[count[0]]));
	}
	count[2]++;
}

void	attrib_d_j(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	char c;
	int k;
	int check;
	int check_double;
	int neg;

	k = 0;
	c = 't';
	neg = 0;
	nbr = ft_nbrlen(var[count[2]]->u_l_long);
	flag = check_flag(str, count, &nbr, &c);
	check = ft_atoi_ultra(str[count[0]]);
	if (flag == 3500)
		check_double = ft_atoi_double(str[count[0]]);
	if (str[count[0]][0] == '.')
		nbr--;
	str[count[0]] = ft_ntoa_base(var[count[2]]->u_l_long, "0123456789");
	if (str[count[0]][0] != '0')
		neg = 1;
	if (flag == 1000)
	{
		neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (flag == 3500)
	{
		while (k < check_double - nbr)
		{
			str[count[0]] = ft_strjoin("0", str[count[0]]);
			k++;
		}
		k = 0;
		while (k < check - check_double)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			k++;
		}
	}
	else if (flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 4000)
	{
		str[count[0]] = ft_strjoin("+", str[count[0]]);
		while (k < check - nbr)
		{
			str[count[0]] = ft_strjoin(str[count[0]], " ");
			k++;
		}
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
	else if (flag != 1 && flag != 1000 && flag != 2000 &&
			flag != 3000 && flag != 4000 && flag != 3500 && flag != 5000)
	{
		if (flag < -1 && c != '0')
		{
			while (k > flag + nbr + neg)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else if (flag > 0 && (c == '0' || c == '.'))
		{
			while (k < flag - nbr - neg)
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
			while (k < flag - nbr - neg)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	count[2]++;
}

void	attrib_s_maj(char **str, t_var **var, int count[3])
{
	int flag;
	int k;
	int i;
	int nbr;
	int p;
	int check;
	int diff;
	int compteur;
	int check_double;
	char *str_2;
	char c;
	char m;;

	k = 0;
	compteur = 0;
	i = 0;
	diff = 0;
	p = 1;
	nbr = 0;
	c = 't';
	check = ft_atoi(str[count[0]]);
	check_double = ft_atoi_double(str[count[0]]);
	flag = check_flag(str, count, &nbr, &c);
	if (str[count[0]][1] == '.' || str[count[0]][2] == '.')
		c = '.';
	if (str[count[0]][0] == '0')
		m = '0';
	str[count[0]] = (char *)malloc(sizeof(char) * 20);
	str_2 = (char *)malloc(sizeof(char) * 20);
	if (var[count[2]]->w_string != 0)
	{
		while (var[count[2]]->w_string[i])
		{
			utf8encode(str_2, var[count[2]]->w_string[i]);
			if (str_2[0] == 32)
				str[count[0]] = ft_strjoin(str[count[0]], " ");
			else
				str[count[0]] = ft_strjoin(str[count[0]], str_2);
			i++;
			compteur++;
		}
	}
	if (flag == 1000 && var[count[2]]->w_string != NULL)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (flag == 2000 && var[count[2]]->w_string != NULL)
	{
	}
	else if (flag == 3000)
	{
		if (var[count[2]]->stars < 0)
		{
			while (k > var[count[2]]->stars + nbr)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else
		{
			while (k < var[count[2]]->stars - nbr)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	else if (flag == 3500)
	{
		if (check_double >= compteur)
			diff = check_double;
		else
			diff = compteur;
		k = 0;
		if (check_double == 0)
			str[count[0]] = ft_strdup("\0");
		while (k < check && check_double == 0)
		{
			str[count[0]] = ft_strjoin("0", str[count[0]]);
			compteur++;
			k++;
		}
		if (m == '0')
			p = 0;
	}
	else if (flag != -1 && flag != 1000 && flag != 2000 && flag != 3500 &&
			flag != 3000 && flag != 4000 && flag != 5000 && c != '.')
	{
		nbr = ft_strlen(str[count[0]]);
		if (flag < -1 && c != '0')
		{
			while (k > flag + nbr)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else
		{
			while (k < flag - nbr)
			{
				if (c == '0')
					str[count[0]] = ft_strjoin("0", str[count[0]]);
				else
					str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	if (var[count[2]]->w_string == NULL && c == '.')
		str[count[0]][0] = '\0';
	else if (var[count[2]]->w_string == NULL && c != '.')
		str[count[0]] = ft_strdup("(null)");
	else if (flag > 0 && c == '.' && check_double != 0 && check == 0)
	{
		flag = flag - flag % 3;
		str[count[0]][flag] = '\0';
	}
	else if (flag > 0 && c == '.' && check_double != 0 && check != 0)
	{
		if (check_double < 3)
			check_double = check_double % 3;
		else
			check_double = check_double - check_double % 3;
		str[count[0]][check_double] = '\0';
		k = 0;
		nbr = ft_strlen(str[count[0]]);
		while (k < check - nbr)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			k++;
		}
	}
	else if (flag > 0 && c == '.' && check_double == 0 && p == 1)
	{
		k = 0;
		str[count[0]][0] = '\0';
		while (k < check)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			k++;
		}
	}
	s_maj = 1;
	count[2]++;
}
