/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 20:35:31 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/28 12:44:24 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <wchar.h>
#include "ft_printf.h"

void	attrib_o_char(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	int k;
	int l;
	char c;

	k = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->u_carac);
	flag = check_flag(str, count, &nbr, &c);
	l = ft_atoi_spec_o(str[count[0]]);
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_carac, "01234567");	
	nbr = ft_strlen(str[count[0]]);
	if (flag == 1000)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 5000)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
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
	if (flag != -1 && flag != 1000 &&
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
	count[2]++;
}

void	attrib_x_char(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	int k;
	int l;
	char c;

	k = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->u_carac);
	l = ft_atoi_spec_o(str[count[0]]);
	flag = check_flag(str, count, &nbr, &c);
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_carac, "0123456789abcdef");
	nbr = ft_strlen(str[count[0]]);
	if (flag == 1000)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 5000)
	{
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
		flag = l;
		nbr++;
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
	if (flag != -1 && flag != 1000 && flag != 2000 &&
			flag != 3000 && flag != 5000)
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
	if (c != '.' && c != '0')
	{
		while (str[count[0]][0] == '0' && str[count[0]][1] != '\0')
			str[count[0]] = ft_strsub(str[count[0]], 1, ft_strlen(str[count[0]]));
	}
	count[2]++;
}

void	attrib_x_maj_char(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	int k;
	int l;
	char c;

	k = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->u_carac);
	l = ft_atoi_spec_o(str[count[0]]);
	flag = check_flag(str, count, &nbr, &c);
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_carac, "0123456789ABCDEF");
	nbr = ft_strlen(str[count[0]]);
	if (flag == 1000)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 5000)
	{
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
		flag = l;
		nbr++;
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
	if (flag != -1 && flag != 1000 && flag != 2000 &&
			flag != 3000 && flag != 5000)
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
	if (c != '.' && c != '0')
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
	if (var[count[2]]->w_string == NULL)
		rajout = 1;
	str[count[0]] = (char *)malloc(sizeof(char) * 20);
	str_2 = (char *)malloc(sizeof(char) * 20);
	while (var[count[2]]->w_string[i])
	{
		utf8encode(str_2, var[count[2]]->w_string[i]);
		str[count[0]] = ft_strjoin(str[count[0]], str_2);
		i++;
		compteur++;
	}
	if (var[count[2]]->w_string == NULL)
		char_nul = count[0];
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
		str[count[0]] = ft_strdup("\0");
		while (k < check)
		{
			str[count[0]] = ft_strjoin("0", str[count[0]]);
			compteur++;
			k++;
		}
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
	else if (flag > 0 && c == '.')
		str[count[0]] = ft_strsub(str[count[0]], 0, flag); // A CHECKER PK MARCHE PAS
	s_maj = 1;
	count[2]++;
}
