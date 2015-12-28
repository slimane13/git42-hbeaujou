/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:32:56 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/28 15:33:18 by hbeaujou         ###   ########.fr       */
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
	int nbr;
	int flag;
	int k;
	int diff;
	int p;
	int check;
	int check_double;
	char c;

	k = 0;
	diff = 0;
	p = 0;
	c = 't';
	nbr = 3;
	check_double = ft_atoi_double(str[count[0]]);
	check = ft_atoi_ultra(str[count[0]]);
	flag = check_flag(str, count, &nbr, &c);
	if (var[count[2]]->u_long != 0 && flag != 3500)
	{
		str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_long, "0123456789abcdef");
		nbr = ft_strlen(str[count[0]]);
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
		nbr = ft_strlen(str[count[0]]) + 2;
	}
	if (flag == 3500)
	{
		str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_long, "0123456789abcdef");
		if (check > check_double)
			str[count[0]] = ft_strjoin("0x", str[count[0]]);
		nbr = ft_strlen(str[count[0]]);
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
		if (check <= check_double)
			str[count[0]] = ft_strjoin("0x", str[count[0]]);
	}
	else if (var[count[2]]->u_long == 0 && c != '.')
		str[count[0]] = ft_strdup("0x0");
	else if (flag != 3500 && var[count[2]]->u_long == 0)
		str[count[0]] = ft_strdup("0x");
	if (flag != 0 && flag < 1000)
	{
		if (var[count[2]]->u_long != 0 || c == '.')
		{
			while (k < flag - nbr + 3)
			{
				str[count[0]] = ft_strjoin(str[count[0]], "0");
				k++;
			}
		}
		else
		{
			if (flag > 0 && c != '0')
			{
				k = 3;
				while (k < flag)
				{
					str[count[0]] = ft_strjoin(" ", str[count[0]]);
					k++;
				}
			}
			else
			{
				if (flag < 0)
					flag = -flag;
				k = 3;
				while (k < flag)
				{
					if (c == '0')
						str[count[0]] = ft_strjoin(str[count[0]], "0");
					else
						str[count[0]] = ft_strjoin(str[count[0]], " ");
					k++;
				}
			}
		}
	}
	count[2]++;
}

void	attrib_x(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	int k;
	int l;
	int check;
	int check_double;
	int diff;
	int p;
	int spec;
	char c;

	k = 0;
	p = 1;
	diff = 0;
	spec = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->u_long);
	l = ft_atoi_spec_o(str[count[0]]);
	check_double = ft_atoi_double(str[count[0]]);
	check = ft_atoi_ultra(str[count[0]]);
	flag = check_flag(str, count, &nbr, &c);
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_long, "0123456789abcdef");
	nbr = ft_strlen(str[count[0]]);
	if (flag == 5000)
	{
		while (k < check_double - nbr)
		{
			str[count[0]] = ft_strjoin("0", str[count[0]]);
			k++;
		}
		if (var[count[2]]->u_long != 0)
			str[count[0]] = ft_strjoin("0x", str[count[0]]);
		flag = l;
		if (var[count[2]]->u_long == 0)
			spec = 0;
		else
			spec = 1;
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
	if (flag != 0 && flag != -1 && flag != 1000 && flag != 2000 &&
			flag != 3500 && flag != 3000 && flag != 5000 && spec == 0)
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
	else if (flag == 0 && c == '.' && spec == 0)
		str[count[0]][0] = '\0';
	count[2]++;
}

void	attrib_x_maj(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	int k;
	int diff;
	int check;
	int check_double;
	int p;
	char c;

	k = 0;
	diff = 0;
	p = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->u_long);
	check_double = ft_atoi_double(str[count[0]]);
	check = ft_atoi_ultra(str[count[0]]);
	flag = check_flag(str, count, &nbr, &c);
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_long, "0123456789ABCDEF");
	nbr = ft_strlen(str[count[0]]);
	if (flag == 5000)
	{
		if (var[count[2]]->u_long != 0)
			str[count[0]] = ft_strjoin("0X", str[count[0]]);
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
	else if (flag != 0 && flag != -1 && flag != 1000 && flag != 3500 &&
			flag != 2000 && flag != 5000)
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
	else if (flag == 0 && c == '.')
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
