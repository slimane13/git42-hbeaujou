/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 20:35:31 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/27 18:29:52 by hbeaujou         ###   ########.fr       */
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
	int str_len;
	int flag;
	int k;
	int diff;
	int check;
	int check_double;
	char c;
	char z;

	k = 0;
	diff = 0;
	c = 't';
	z = 'o';
	str_len = 7;
	check = ft_atoi_ultra(str[count[0]]);
	check_double = ft_atoi_double(str[count[0]]);
	flag = check_flag(str, count, &str_len, &c);
	printf("flag %d\ncheck %d\ncheck_double %d\nchar %c\n", flag, check, check_double, c);
	printf("var %d\n", var[count[2]]->w_string == NULL);
	if (str[count[0]][0] == '.' || str[count[0]][1] == '.' ||
			str[count[0]][2] == '.')
		c = '.';
	if (str[count[0]][0] == '0')
		z = '0';
	if (var[count[2]]->w_string == NULL && c != '.')
		flag = -1;
	if (var[count[2]]->w_string != NULL)
	{
//		wprintf(L"%s\n", var[count[2]]->w_string);
		wcstombs(str[count[0]], var[count[2]]->w_string, sizeof(str[count[2]])); // A FAIRE A LA MAIN
	}
	if (var[count[2]]->w_string != NULL)
		str_len = ft_strlen((char *)var[count[2]]->w_string);
	if (flag == -1)
		str[count[0]] = ft_strcpy(str[count[0]], "(null)");
	else if (flag == 3500)
	{
		if (check_double < str_len)
			str[count[0]] = ft_strsub(str[count[0]], 0, check_double);
		str_len = ft_strlen(str[count[0]]);
		if (check_double >= str_len)
			diff = check_double;
		else
			diff = str_len;
		if (check < check_double)
			check_double = check;
		while (k < check_double - str_len)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			k++;
		}
		k = 0;
		while (k < check - diff)
		{
			if (z == '0')
				str[count[0]] = ft_strjoin("0", str[count[0]]);
			else
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
			k++;
		}
	}
	else if (flag != 0 && flag != -1 && flag != 1000 && flag != 2000 &&
			flag != 3000 && flag != 4000 && flag != 5000 && flag != 3500)
	{
		if (flag < -1 && c != '0')
		{
			while (k > flag + str_len)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else if (flag == 0 && c == '.')
			str[count[0]][0] = '\0';
		else if (flag > 0 && c == '.')
		{
			if (flag < 0)
				flag = -flag;
			str[count[0]] = ft_strsub(str[count[0]], 0, flag);
		}
		else if (c == '0')
		{
			while (k < flag - str_len)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
			}
		}
		else
		{
			while (k < flag - str_len)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
//	str[count[0]] = ft_strdup("\0");
//	char_nul = 200;
//	rajout = -1;
	s_maj = 1;
	count[2]++;
}
